#!/usr/bin/env wolframscript
(* ::Package:: *)

(* Script assumptions :
    1.  Script has not changed directories, as with SetDirectory[]
    2.  Mathematica 11.0, or later
    3.  This file is only launched from console, not from interactive input mode
*)
RulePointExpand::para="Not sufficient parameters. At least `1` required while `2` is received. Received parameters are `3`";
If[Length[$ScriptCommandLine]<3,
Message[RulePointExpand::para,3,Length[$ScriptCommandLine],$ScriptCommandLine];Exit[10],
Nothing[]
]

rulepath=($ScriptCommandLine)[[2]];
dstpath=($ScriptCommandLine)[[3]];

scriptPath = ExpandFileName[First[$ScriptCommandLine]]; 
scriptName = Last[FileNameSplit[scriptPath]]; 

Print["Script ", scriptPath, " is using Markdown files in ", rulepath, " to generate headers in ", dstpath];

If[Length[$ScriptCommandLine]>=4, targetCUDAver=($ScriptCommandLine)[[4]];,targetCUDAver="11.5";]
If[Length[$ScriptCommandLine]>=5, targetHIPver=($ScriptCommandLine)[[5]];,targetHIPver="4.3.0";]
If[Length[$ScriptCommandLine]>=6, prefix=($ScriptCommandLine)[[6]];,prefix="DAPI";]

verge[ver1_,ver2_]:=Module[
{intver1,intver2},
intver1=Join[ToExpression[StringSplit[ver1,"."]],{0,0,0}][[1;;3]];
intver2=Join[ToExpression[StringSplit[ver2,"."]],{0,0,0}][[1;;3]];
(Total[(intver1-intver2)*{100000000,10000,1}]>=0)||(StringTrim[ver2]=="")
]

mds=FileNames[FileNameJoin[{rulepath,"*.md"}]];
lowerprefix=ToLowerCase[prefix];

headersmapCUDA={
    "CUBLAS"->{"cuda_runtime.h", "cublas_v2.h", "cublasXt.h"},
    "CUDA_Device"->{},
    "CUDA_Driver"->{"cuda.h"},
    "CUDA_RTC"->{"nvrtc.h"},
    "CUDA_Runtime"->{"cuda_runtime.h", "device_launch_parameters.h"},
    "CUDNN"->{"cudnn.h"},
    "CUFFT"->{"cuda_runtime.h", "cufft.h", "cufftXt.h"},
    "CURAND"->{"cuda_runtime.h", "curand.h"},
    "CUSPARSE"->{"cuda_runtime.h", "cusparse.h"},
    "cuComplex"->{"cuda_runtime.h", "cuComplex.h"}
}

headersmapHIP={
    "CUBLAS"->{"hip/hip_runtime.h", "hipblas.h"},
    "CUDA_Device"->{},
    "CUDA_Driver"->{"hip/hip_runtime.h"},
    "CUDA_RTC"->{"hip/hip_runtime.h", "hiprtc.h"},
    "CUDA_Runtime"->{"hip/hip_runtime.h"},
    "CUDNN"->{"hipDNN.h"},
    "CUFFT"->{"hip/hip_runtime.h", "hipfft.h", "hipfftXt.h"},
    "CURAND"->{"hip/hip_runtime.h", "hiprand.h"},
    "CUSPARSE"->{"hip/hip_runtime.h", "hipsparse.h"},
    "cuComplex"->{"hip/hip_runtime.h", "hip_complex.h"}
}

Table[
filename=mds[[i]];
shortname=StringSplit[FileNameSplit[filename][[-1]],"_API_"][[1]];


tablesinmd=Select[StringSplit[#,"|"]&/@StringTrim/@StringSplit[Import[filename],"\n"],Length[#]==9&];
tablesinmd=Select[tablesinmd,(StringTrim@#[[1]])!="**CUDA**"&&(StringTrim@#[[1]])!=":--"&];
validhiprule=Select[tablesinmd,StringTrim[#[[5]]]!=""&];
validhiprule=Table[StringTrim/@validhiprule[[i]],{i,1,Length[validhiprule]}];
selecthiprule=Select[validhiprule,
(
verge[targetCUDAver,#[[2]]]
&&verge[targetHIPver,#[[6]]]
&&#[[1]]!="`__CUDACC__`"
&&(#[[1]]!="`cuTexObjectGetTextureDesc`"||#[[5]]!="`hipGetTextureObjectTextureDesc`")(*Special Workaround to remove redefine macros, two different symbols in hip defined for this*)
)&];
topsnames=StringReplace[selecthiprule[[All,1]],{
"`"~~a:RegularExpression["[a-z]"]:>"`"<>lowerprefix<>"_"<>a,
"`"~~a:RegularExpression["_"]:>"`"<>lowerprefix<>"_"<>a,
"`"~~a:RegularExpression["[A-Z]"]:>"`"<>prefix<>"_"<>a
}];
relname=StringReplace[FileNameTake[filename,-4],"\\"->"/"];
makedefs[names1_,names2_,apitype_]:=
StringRiffle[
Join[
    ("#include <"<>StringTrim[#]<>">")&/@If[apitype=="CUDA", shortname/.headersmapCUDA, shortname/.headersmapHIP],
    ("#define "<>StringTrim[#[[1]],"`"]<>" "<>StringTrim[#[[2]],"`"])&/@Transpose[{names1,names2}]
],
{"#ifdef "<>prefix<>"_GPU_API_"<>apitype<>"\n\n",
"\n",
"\n\n#endif //"<>prefix<>"_GPU_API_"<>apitype<>"\n"
}
];

filecontent=
"//This file is generated from "<>relname<>" with the restriction of <CUDA Ver.> <= "<>targetCUDAver<>" and <HIP Ver.> <= "<>targetHIPver<>".\n"<>
"//The prefix is selected as "<>prefix <>" and its corresponding lower case.\n\n"<>
"#pragma once\n\n"<>
makedefs[topsnames,selecthiprule[[All,1]],"CUDA"]<>"\n\n"<>
makedefs[topsnames,selecthiprule[[All,5]],"HIP"];
Export[FileNameJoin[{dstpath,"device_api_"<>ToLowerCase[shortname]<>".h"}],filecontent,"Text"]
,{i,1,Length[mds]}]