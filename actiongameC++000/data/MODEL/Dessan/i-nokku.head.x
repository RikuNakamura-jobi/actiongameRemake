xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 121;
 -0.00000;0.12635;1.97603;,
 -1.39727;0.12635;1.39726;,
 -0.00000;0.12635;0.00000;,
 1.39726;0.12635;1.39726;,
 1.97603;0.12635;0.00000;,
 1.39726;0.12635;-1.39727;,
 1.97603;0.12635;0.00000;,
 -0.00000;0.12635;0.00000;,
 -0.00000;0.12635;-1.97603;,
 -1.39727;0.12635;-1.39727;,
 -1.97603;0.12635;0.00000;,
 -1.97603;0.12635;0.00000;,
 -1.71099;5.12785;1.71099;,
 -0.91291;6.13643;0.91290;,
 -1.29104;6.13643;0.00000;,
 -2.41971;5.12785;0.00000;,
 -0.00000;5.12785;2.41971;,
 -0.00000;6.13643;1.29103;,
 1.71099;5.12785;1.71099;,
 0.91290;6.13643;0.91290;,
 2.41971;5.12785;0.00000;,
 1.29103;6.13643;0.00000;,
 1.29103;6.13643;0.00000;,
 2.41971;5.12785;0.00000;,
 1.71099;5.12785;-1.71099;,
 0.91290;6.13643;-0.91290;,
 -0.00000;5.12785;-2.41971;,
 -0.00000;6.13643;-1.29104;,
 -1.71099;5.12785;-1.71099;,
 -0.91291;6.13643;-0.91290;,
 -2.41971;5.12785;0.00000;,
 -1.29104;6.13643;0.00000;,
 -1.39727;0.12635;1.39726;,
 -0.00000;0.12635;1.97603;,
 -0.00000;5.12785;2.41971;,
 -1.71099;5.12785;1.71099;,
 1.39726;0.12635;1.39726;,
 1.71099;5.12785;1.71099;,
 -0.91291;6.13643;0.91290;,
 -0.00000;6.13643;1.29103;,
 -0.00000;6.42834;0.00000;,
 0.91290;6.13643;0.91290;,
 0.00000;10.67479;0.00000;,
 0.94303;10.40951;-0.94303;,
 0.00000;10.40951;-1.33365;,
 0.00000;10.67479;0.00000;,
 1.33365;10.40951;0.00000;,
 0.00000;10.67479;0.00000;,
 0.94303;10.40951;0.94303;,
 0.00000;10.67479;0.00000;,
 -0.00000;10.40951;1.33365;,
 0.00000;10.67479;0.00000;,
 -0.94303;10.40951;0.94303;,
 0.00000;10.67479;0.00000;,
 -1.33365;10.40951;-0.00000;,
 0.00000;10.67479;0.00000;,
 -0.94303;10.40951;-0.94303;,
 0.00000;10.67479;0.00000;,
 0.00000;10.40951;-1.33365;,
 1.74250;9.65406;-1.74250;,
 0.00000;9.65406;-2.46427;,
 2.46427;9.65406;0.00000;,
 1.74250;9.65406;1.74250;,
 -0.00000;9.65406;2.46427;,
 -1.74250;9.65406;1.74250;,
 -2.46427;9.65406;-0.00000;,
 -1.74250;9.65406;-1.74250;,
 0.00000;9.65406;-2.46427;,
 2.27669;8.52344;-2.27669;,
 0.00000;8.52344;-3.21972;,
 3.21972;8.52344;0.00000;,
 2.27669;8.52344;2.27669;,
 -0.00000;8.52344;3.21972;,
 -2.27669;8.52344;2.27669;,
 -3.21972;8.52344;-0.00000;,
 -2.27669;8.52344;-2.27669;,
 0.00000;8.52344;-3.21972;,
 2.46427;7.18979;-2.46427;,
 0.00000;7.18979;-3.48500;,
 3.48500;7.18979;0.00000;,
 2.46427;7.18979;2.46427;,
 -0.00000;7.18979;3.48500;,
 -2.46427;7.18979;2.46427;,
 -3.48500;7.18979;-0.00000;,
 -2.46427;7.18979;-2.46427;,
 0.00000;7.18979;-3.48500;,
 2.27669;5.85614;-2.27669;,
 0.00000;5.85614;-3.21972;,
 3.21972;5.85614;0.00000;,
 2.27669;5.85614;2.27669;,
 -0.00000;5.85614;3.21972;,
 -2.27669;5.85614;2.27669;,
 -3.21972;5.85614;-0.00000;,
 -2.27669;5.85614;-2.27669;,
 0.00000;5.85614;-3.21972;,
 1.74250;4.72553;-1.74250;,
 0.00000;4.72553;-2.46427;,
 2.46427;4.72553;0.00000;,
 1.74250;4.72553;1.74250;,
 -0.00000;4.72553;2.46427;,
 -1.74250;4.72553;1.74250;,
 -2.46427;4.72553;-0.00000;,
 -1.74250;4.72553;-1.74250;,
 0.00000;4.72553;-2.46427;,
 0.94303;3.97007;-0.94303;,
 0.00000;3.97007;-1.33365;,
 1.33365;3.97007;0.00000;,
 0.94303;3.97007;0.94303;,
 -0.00000;3.97007;1.33365;,
 -0.94303;3.97007;0.94303;,
 -1.33365;3.97007;-0.00000;,
 -0.94303;3.97007;-0.94303;,
 0.00000;3.97007;-1.33365;,
 0.00000;3.70479;0.00000;,
 0.00000;3.70479;0.00000;,
 0.00000;3.70479;0.00000;,
 0.00000;3.70479;0.00000;,
 0.00000;3.70479;0.00000;,
 0.00000;3.70479;0.00000;,
 0.00000;3.70479;0.00000;,
 0.00000;3.70479;0.00000;;
 
 96;
 3;0,1,2;,
 3;3,0,2;,
 3;4,3,2;,
 3;5,6,7;,
 3;8,5,7;,
 3;9,8,7;,
 3;10,9,7;,
 3;1,11,2;,
 4;12,13,14,15;,
 4;13,12,16,17;,
 4;17,16,18,19;,
 4;19,18,20,21;,
 4;22,23,24,25;,
 4;25,24,26,27;,
 4;27,26,28,29;,
 4;29,28,30,31;,
 4;32,33,34,35;,
 4;33,36,37,34;,
 4;3,4,20,18;,
 4;6,5,24,23;,
 4;5,8,26,24;,
 4;8,9,28,26;,
 4;9,10,30,28;,
 4;11,1,12,15;,
 3;38,39,40;,
 3;39,41,40;,
 3;41,22,40;,
 3;22,25,40;,
 3;25,27,40;,
 3;27,29,40;,
 3;29,31,40;,
 3;31,38,40;,
 3;42,43,44;,
 3;45,46,43;,
 3;47,48,46;,
 3;49,50,48;,
 3;51,52,50;,
 3;53,54,52;,
 3;55,56,54;,
 3;57,58,56;,
 4;44,43,59,60;,
 4;43,46,61,59;,
 4;46,48,62,61;,
 4;48,50,63,62;,
 4;50,52,64,63;,
 4;52,54,65,64;,
 4;54,56,66,65;,
 4;56,58,67,66;,
 4;60,59,68,69;,
 4;59,61,70,68;,
 4;61,62,71,70;,
 4;62,63,72,71;,
 4;63,64,73,72;,
 4;64,65,74,73;,
 4;65,66,75,74;,
 4;66,67,76,75;,
 4;69,68,77,78;,
 4;68,70,79,77;,
 4;70,71,80,79;,
 4;71,72,81,80;,
 4;72,73,82,81;,
 4;73,74,83,82;,
 4;74,75,84,83;,
 4;75,76,85,84;,
 4;78,77,86,87;,
 4;77,79,88,86;,
 4;79,80,89,88;,
 4;80,81,90,89;,
 4;81,82,91,90;,
 4;82,83,92,91;,
 4;83,84,93,92;,
 4;84,85,94,93;,
 4;87,86,95,96;,
 4;86,88,97,95;,
 4;88,89,98,97;,
 4;89,90,99,98;,
 4;90,91,100,99;,
 4;91,92,101,100;,
 4;92,93,102,101;,
 4;93,94,103,102;,
 4;96,95,104,105;,
 4;95,97,106,104;,
 4;97,98,107,106;,
 4;98,99,108,107;,
 4;99,100,109,108;,
 4;100,101,110,109;,
 4;101,102,111,110;,
 4;102,103,112,111;,
 3;105,104,113;,
 3;104,106,114;,
 3;106,107,115;,
 3;107,108,116;,
 3;108,109,117;,
 3;109,110,118;,
 3;110,111,119;,
 3;111,112,120;;
 
 MeshMaterialList {
  5;
  96;
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.401600;0.401600;0.401600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\enoch_400x400.jpg";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  84;
  0.000000;-1.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  -0.654804;0.377444;0.654803;,
  -0.321248;0.890842;0.321249;,
  -0.000000;0.377445;0.926032;,
  -0.000000;0.890842;0.454314;,
  0.654803;0.377445;0.654804;,
  0.321248;0.890842;0.321248;,
  0.926032;0.377445;0.000000;,
  0.454314;0.890842;0.000000;,
  0.654804;0.377445;-0.654803;,
  0.321248;0.890842;-0.321248;,
  -0.000001;0.377445;-0.926032;,
  -0.000000;0.890842;-0.454313;,
  -0.654805;0.377444;-0.654803;,
  -0.321249;0.890842;-0.321248;,
  -0.926033;0.377444;0.000000;,
  -0.454315;0.890841;0.000000;,
  -0.704341;-0.088362;0.704340;,
  -0.000001;-0.088362;0.996088;,
  0.704341;-0.088362;0.704341;,
  0.996089;-0.088361;0.000001;,
  0.704341;-0.088362;-0.704340;,
  -0.000001;-0.088362;-0.996088;,
  -0.704342;-0.088362;-0.704340;,
  -0.996089;-0.088361;0.000001;,
  -0.000000;1.000000;0.000000;,
  -0.000000;0.924735;-0.380611;,
  0.269132;0.924735;-0.269132;,
  0.380611;0.924735;0.000000;,
  0.269132;0.924735;0.269132;,
  -0.000000;0.924735;0.380611;,
  -0.269132;0.924735;0.269132;,
  -0.380611;0.924735;0.000000;,
  -0.269132;0.924735;-0.269132;,
  -0.000000;0.709230;-0.704977;,
  0.498494;0.709230;-0.498494;,
  0.704977;0.709230;0.000000;,
  0.498494;0.709230;0.498494;,
  -0.000000;0.709230;0.704977;,
  -0.498494;0.709230;0.498494;,
  -0.704977;0.709230;0.000000;,
  -0.498494;0.709230;-0.498494;,
  -0.000000;0.384551;-0.923104;,
  0.652733;0.384551;-0.652733;,
  0.923104;0.384551;0.000000;,
  0.652733;0.384551;0.652733;,
  -0.000000;0.384551;0.923104;,
  -0.652733;0.384551;0.652733;,
  -0.923104;0.384551;0.000000;,
  -0.652733;0.384551;-0.652733;,
  -0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  -0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;0.000000;,
  -0.707107;-0.000000;-0.707107;,
  -0.000000;-0.384551;-0.923104;,
  0.652733;-0.384551;-0.652733;,
  0.923104;-0.384551;0.000000;,
  0.652733;-0.384551;0.652733;,
  -0.000000;-0.384551;0.923104;,
  -0.652733;-0.384551;0.652733;,
  -0.923104;-0.384551;0.000000;,
  -0.652733;-0.384551;-0.652733;,
  -0.000000;-0.709230;-0.704977;,
  0.498494;-0.709230;-0.498494;,
  0.704977;-0.709230;0.000000;,
  0.498494;-0.709230;0.498494;,
  -0.000000;-0.709230;0.704977;,
  -0.498494;-0.709230;0.498494;,
  -0.704977;-0.709230;-0.000000;,
  -0.498494;-0.709230;-0.498494;,
  -0.000000;-0.924735;-0.380611;,
  0.269133;-0.924735;-0.269133;,
  0.380611;-0.924735;0.000000;,
  0.269133;-0.924735;0.269133;,
  -0.000000;-0.924735;0.380611;,
  -0.269133;-0.924735;0.269132;,
  -0.380611;-0.924735;-0.000000;,
  -0.269133;-0.924735;-0.269132;,
  -0.000000;-1.000000;-0.000000;;
  96;
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;2,3,17,16;,
  4;3,2,4,5;,
  4;5,4,6,7;,
  4;7,6,8,9;,
  4;9,8,10,11;,
  4;11,10,12,13;,
  4;13,12,14,15;,
  4;15,14,16,17;,
  4;18,19,4,2;,
  4;19,20,6,4;,
  4;20,21,8,6;,
  4;21,22,10,8;,
  4;22,23,12,10;,
  4;23,24,14,12;,
  4;24,25,16,14;,
  4;25,18,2,16;,
  3;3,5,1;,
  3;5,7,1;,
  3;7,9,1;,
  3;9,11,1;,
  3;11,13,1;,
  3;13,15,1;,
  3;15,17,1;,
  3;17,3,1;,
  3;26,28,27;,
  3;26,29,28;,
  3;26,30,29;,
  3;26,31,30;,
  3;26,32,31;,
  3;26,33,32;,
  3;26,34,33;,
  3;26,27,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,33,41,40;,
  4;33,34,42,41;,
  4;34,27,35,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,41,49,48;,
  4;41,42,50,49;,
  4;42,35,43,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,49,57,56;,
  4;49,50,58,57;,
  4;50,43,51,58;,
  4;51,52,60,59;,
  4;52,53,61,60;,
  4;53,54,62,61;,
  4;54,55,63,62;,
  4;55,56,64,63;,
  4;56,57,65,64;,
  4;57,58,66,65;,
  4;58,51,59,66;,
  4;59,60,68,67;,
  4;60,61,69,68;,
  4;61,62,70,69;,
  4;62,63,71,70;,
  4;63,64,72,71;,
  4;64,65,73,72;,
  4;65,66,74,73;,
  4;66,59,67,74;,
  4;67,68,76,75;,
  4;68,69,77,76;,
  4;69,70,78,77;,
  4;70,71,79,78;,
  4;71,72,80,79;,
  4;72,73,81,80;,
  4;73,74,82,81;,
  4;74,67,75,82;,
  3;75,76,83;,
  3;76,77,83;,
  3;77,78,83;,
  3;78,79,83;,
  3;79,80,83;,
  3;80,81,83;,
  3;81,82,83;,
  3;82,75,83;;
 }
 MeshTextureCoords {
  121;
  0.500000;0.718477;,
  0.625000;0.718477;,
  0.750000;0.718477;,
  0.375000;0.718477;,
  0.250000;0.718477;,
  0.413478;0.589780;,
  0.347710;0.583981;,
  0.554796;0.583690;,
  0.562028;0.592013;,
  0.706341;0.589369;,
  0.761881;0.583399;,
  0.750000;0.718477;,
  0.625000;0.371694;,
  0.625000;0.301764;,
  0.750000;0.301764;,
  0.750000;0.371694;,
  0.500000;0.371694;,
  0.500001;0.301764;,
  0.375000;0.371694;,
  0.375000;0.301764;,
  0.250000;0.371694;,
  0.250000;0.301764;,
  0.419498;0.100578;,
  0.301214;0.181849;,
  0.381748;0.188951;,
  0.462466;0.104367;,
  0.563651;0.191684;,
  0.559521;0.105825;,
  0.740367;0.188448;,
  0.653808;0.104099;,
  0.808378;0.181137;,
  0.690095;0.100198;,
  0.132380;-0.060940;,
  0.478721;-0.060940;,
  0.478721;-0.813808;,
  0.054617;-0.813808;,
  0.825062;-0.060940;,
  0.902825;-0.813808;,
  0.647126;0.096409;,
  0.550071;0.094950;,
  0.554796;0.076913;,
  0.455785;0.096677;,
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}