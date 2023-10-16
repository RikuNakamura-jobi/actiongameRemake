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
 90;
 -0.00010;2.52700;-39.52060;,
 -27.94540;2.52700;-27.94530;,
 -0.00010;2.52700;0.00000;,
 27.94530;2.52700;-27.94530;,
 39.52060;2.52700;0.00000;,
 27.94530;2.52700;27.94540;,
 -0.00010;2.52700;39.52070;,
 -27.94540;2.52700;27.94540;,
 -39.52070;2.52700;0.00000;,
 -34.21990;102.55700;-34.21980;,
 -18.25810;122.72850;-18.25800;,
 -25.82080;122.72850;0.00000;,
 -48.39420;102.55700;0.00000;,
 -18.25810;122.72850;-18.25800;,
 -34.21990;102.55700;-34.21980;,
 -0.00010;102.55700;-48.39420;,
 -0.00010;122.72850;-25.82060;,
 -0.00010;122.72850;-25.82060;,
 34.21980;102.55700;-34.21980;,
 18.25790;122.72850;-18.25800;,
 18.25790;122.72850;-18.25800;,
 48.39410;102.55700;0.00000;,
 25.82060;122.72850;0.00000;,
 25.82060;122.72850;0.00000;,
 34.21980;102.55700;34.21990;,
 18.25790;122.72850;18.25800;,
 18.25790;122.72850;18.25800;,
 -0.00010;102.55700;48.39430;,
 -0.00010;122.72850;25.82070;,
 -0.00010;122.72850;25.82070;,
 -34.21990;102.55700;34.21990;,
 -18.25810;122.72850;18.25800;,
 -18.25810;122.72850;18.25800;,
 -25.82080;122.72850;0.00000;,
 -27.94540;2.52700;-27.94530;,
 -0.00010;2.52700;-39.52060;,
 27.94530;2.52700;-27.94530;,
 39.52060;2.52700;0.00000;,
 27.94530;2.52700;27.94540;,
 -0.00010;2.52700;39.52070;,
 -27.94540;2.52700;27.94540;,
 -39.52070;2.52700;0.00000;,
 -27.94540;2.52700;-27.94530;,
 -18.25810;122.72850;-18.25800;,
 -0.00010;122.72850;-25.82060;,
 -0.00010;128.56680;0.00000;,
 18.25790;122.72850;-18.25800;,
 25.82060;122.72850;0.00000;,
 18.25790;122.72850;18.25800;,
 -0.00010;122.72850;25.82070;,
 -18.25810;122.72850;18.25800;,
 -25.82080;122.72850;0.00000;,
 -48.76770;102.42090;0.81070;,
 -48.69400;102.39610;8.72310;,
 -47.40230;87.36150;0.28700;,
 47.59970;84.78520;0.07800;,
 49.27000;102.63430;7.12650;,
 49.17330;102.66520;1.23960;,
 -48.84110;102.44550;-7.07130;,
 -27.25900;122.92630;-7.15790;,
 -27.00580;122.68720;1.07950;,
 -26.78400;122.47780;8.29060;,
 -0.00090;128.71941;1.24890;,
 0.02980;128.68581;7.98640;,
 -0.03950;128.76160;-7.22390;,
 26.61000;122.94170;7.58460;,
 26.52960;122.97920;1.31530;,
 26.42010;123.03040;-7.23570;,
 49.03010;102.71110;-7.47670;,
 0.02980;128.68581;7.98640;,
 -0.00090;128.71941;1.24890;,
 -0.03950;128.76160;-7.22390;,
 -47.40230;87.36150;0.28700;,
 -48.76770;102.42090;0.81070;,
 -51.31360;102.76740;-2.85700;,
 -49.87350;113.71100;5.23330;,
 -40.61440;124.65510;-3.18710;,
 -27.00580;122.68720;1.07950;,
 -28.28090;131.33820;5.49780;,
 -15.34370;135.95180;-3.35880;,
 -0.00090;128.71941;1.24890;,
 -0.00550;139.51990;2.59580;,
 14.45550;137.02350;-5.47510;,
 26.52960;122.97920;1.31530;,
 28.40100;132.63451;5.57980;,
 40.09230;125.43920;-3.84600;,
 49.17330;102.66520;1.23960;,
 49.12680;115.40090;3.96030;,
 52.26260;103.06500;-2.34660;,
 47.59970;84.78520;0.07800;;
 
 76;
 3;2,1,0;,
 3;2,0,3;,
 3;2,3,4;,
 3;2,4,5;,
 3;2,5,6;,
 3;2,6,7;,
 3;2,7,8;,
 3;2,8,1;,
 4;12,11,10,9;,
 4;16,15,14,13;,
 4;19,18,15,17;,
 4;22,21,18,20;,
 4;25,24,21,23;,
 4;28,27,24,26;,
 4;31,30,27,29;,
 4;33,12,30,32;,
 4;14,15,35,34;,
 4;15,18,36,35;,
 4;18,21,37,36;,
 4;21,24,38,37;,
 4;24,27,39,38;,
 4;27,30,40,39;,
 4;30,12,41,40;,
 4;12,9,42,41;,
 3;45,44,43;,
 3;45,46,44;,
 3;45,47,46;,
 3;45,48,47;,
 3;45,49,48;,
 3;45,50,49;,
 3;45,51,50;,
 3;45,43,51;,
 3;54,53,52;,
 3;57,56,55;,
 4;60,59,58,52;,
 4;53,61,60,52;,
 4;60,61,63,62;,
 4;64,59,60,62;,
 4;66,65,56,57;,
 4;68,67,66,57;,
 4;70,69,65,66;,
 4;67,71,70,66;,
 3;52,58,54;,
 3;68,57,55;,
 3;74,73,72;,
 3;72,73,74;,
 3;75,73,74;,
 3;74,73,75;,
 3;76,73,75;,
 3;75,73,76;,
 3;77,73,76;,
 3;76,73,77;,
 3;78,77,76;,
 3;76,77,78;,
 3;79,77,78;,
 3;78,77,79;,
 3;80,77,79;,
 3;79,77,80;,
 3;81,79,80;,
 3;80,79,81;,
 3;82,81,80;,
 3;80,81,82;,
 3;83,80,82;,
 3;82,80,83;,
 3;84,83,82;,
 3;82,83,84;,
 3;85,83,84;,
 3;84,83,85;,
 3;86,83,85;,
 3;85,83,86;,
 3;87,86,85;,
 3;85,86,87;,
 3;88,86,87;,
 3;87,86,88;,
 3;86,89,88;,
 3;88,89,86;;
 
 MeshMaterialList {
  4;
  76;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
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
   TextureFilename {
    "data\\TEXTURE\\wood000.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\whitemaid000.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\whitemaid000.jpg";
   }
  }
 }
 MeshNormals {
  83;
  0.000000;-1.000000;-0.000000;,
  0.000000;1.000000;-0.000000;,
  -0.654804;0.377444;-0.654803;,
  -0.321248;0.890842;-0.321249;,
  -0.000000;0.377445;-0.926032;,
  -0.000000;0.890842;-0.454314;,
  0.654803;0.377445;-0.654804;,
  0.321248;0.890842;-0.321248;,
  0.926032;0.377445;-0.000000;,
  0.454314;0.890842;-0.000000;,
  0.654804;0.377445;0.654803;,
  0.321248;0.890842;0.321248;,
  -0.000001;0.377445;0.926032;,
  -0.000000;0.890842;0.454313;,
  -0.654805;0.377444;0.654803;,
  -0.321249;0.890842;0.321248;,
  -0.926033;0.377444;-0.000000;,
  -0.454315;0.890841;-0.000000;,
  -0.704341;-0.088362;-0.704340;,
  -0.000001;-0.088362;-0.996088;,
  0.704341;-0.088362;-0.704341;,
  0.996089;-0.088361;-0.000001;,
  0.704341;-0.088362;0.704340;,
  -0.000001;-0.088362;0.996088;,
  -0.704342;-0.088362;0.704340;,
  -0.996089;-0.088361;-0.000001;,
  -0.974965;-0.095383;0.200861;,
  -0.934803;0.354652;0.019138;,
  -0.933176;0.358907;0.019171;,
  0.929836;0.367762;-0.012519;,
  0.929968;0.367427;-0.012517;,
  0.971585;-0.099462;0.214777;,
  -0.466132;0.884397;0.023730;,
  -0.465757;0.884594;0.023733;,
  -0.005345;0.999910;0.012284;,
  -0.001110;0.999925;0.012205;,
  0.454614;0.890688;-0.001065;,
  0.455027;0.890477;-0.001064;,
  -0.978919;0.182583;0.091545;,
  -0.539376;0.829467;-0.145116;,
  0.021031;0.979451;0.200585;,
  0.454821;0.890582;-0.001064;,
  0.972135;0.212211;0.099601;,
  0.814775;0.190563;-0.547565;,
  0.799772;0.285244;-0.528206;,
  -0.764813;0.168658;-0.621784;,
  -0.161297;0.429926;-0.888340;,
  -0.069532;0.006340;-0.997560;,
  0.073409;-0.123384;0.989640;,
  0.309076;0.212536;0.926985;,
  0.646535;0.199866;-0.736238;,
  -0.365032;0.063813;-0.928805;,
  0.733949;0.144457;-0.663664;,
  -0.758707;0.121051;-0.640086;,
  0.821986;0.094060;-0.561687;,
  0.679668;0.042967;-0.732261;,
  -0.814775;-0.190563;0.547565;,
  -0.799772;-0.285244;0.528206;,
  0.764813;-0.168658;0.621784;,
  0.311933;0.111398;-0.943551;,
  0.243546;-0.065633;-0.967666;,
  -0.018546;-0.031288;0.999338;,
  -0.254292;0.260705;0.931326;,
  -0.311933;-0.111398;0.943551;,
  0.161297;-0.429926;0.888340;,
  0.069532;-0.006340;0.997560;,
  -0.040901;-0.183218;-0.982221;,
  0.015319;0.059411;0.998116;,
  -0.073409;0.123384;-0.989640;,
  -0.309076;-0.212536;-0.926985;,
  -0.287889;-0.142831;-0.946953;,
  0.287889;0.142831;0.946953;,
  -0.646535;-0.199866;0.736238;,
  -0.388112;0.434257;-0.812890;,
  0.365032;-0.063813;0.928805;,
  0.388112;-0.434257;0.812890;,
  -0.636576;-0.026181;-0.770769;,
  0.286761;0.316278;0.904288;,
  -0.733949;-0.144457;0.663664;,
  -0.758171;0.133575;-0.638228;,
  0.758707;-0.121051;0.640086;,
  0.758171;-0.133575;0.638228;,
  -0.759122;0.108508;-0.641841;;
  76;
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  3;0,0,0;,
  4;16,17,3,2;,
  4;5,4,2,3;,
  4;7,6,4,5;,
  4;9,8,6,7;,
  4;11,10,8,9;,
  4;13,12,10,11;,
  4;15,14,12,13;,
  4;17,16,14,15;,
  4;2,4,19,18;,
  4;4,6,20,19;,
  4;6,8,21,20;,
  4;8,10,22,21;,
  4;10,12,23,22;,
  4;12,14,24,23;,
  4;14,16,25,24;,
  4;16,2,18,25;,
  3;1,5,3;,
  3;1,7,5;,
  3;1,9,7;,
  3;1,11,9;,
  3;1,13,11;,
  3;1,15,13;,
  3;1,17,15;,
  3;1,3,17;,
  3;26,28,38;,
  3;42,29,31;,
  4;39,32,27,38;,
  4;28,33,39,38;,
  4;39,33,34,40;,
  4;35,32,39,40;,
  4;41,36,29,42;,
  4;30,37,41,42;,
  4;40,34,36,41;,
  4;37,35,40,41;,
  3;38,27,26;,
  3;30,42,31;,
  3;43,55,54;,
  3;26,38,56;,
  3;44,55,43;,
  3;56,38,57;,
  3;45,38,45;,
  3;58,58,58;,
  3;60,55,59;,
  3;63,62,61;,
  3;46,60,59;,
  3;63,61,64;,
  3;47,39,46;,
  3;64,61,65;,
  3;66,60,47;,
  3;65,61,67;,
  3;48,65,67;,
  3;66,47,68;,
  3;49,48,67;,
  3;66,68,69;,
  3;70,66,69;,
  3;49,40,71;,
  3;50,50,50;,
  3;72,72,72;,
  3;51,70,73;,
  3;75,71,74;,
  3;76,70,51;,
  3;74,71,77;,
  3;52,42,52;,
  3;78,78,78;,
  3;53,76,79;,
  3;81,42,80;,
  3;42,31,80;,
  3;53,82,76;;
 }
 MeshTextureCoords {
  90;
  0.600790;0.347650;,
  0.624120;0.337990;,
  0.600790;0.315980;,
  0.577460;0.337990;,
  0.567800;0.314660;,
  0.577460;0.291330;,
  0.600790;0.281670;,
  0.624120;0.291330;,
  0.633780;0.314660;,
  0.358680;0.694800;,
  0.341350;0.696830;,
  0.339360;0.708130;,
  0.354940;0.715970;,
  0.352420;0.864570;,
  0.369860;0.864310;,
  0.363370;0.843810;,
  0.348960;0.853630;,
  0.345950;0.842870;,
  0.358300;0.822910;,
  0.343250;0.831720;,
  0.340990;0.820780;,
  0.354690;0.801720;,
  0.339060;0.809470;,
  0.337560;0.798400;,
  0.352530;0.780330;,
  0.336410;0.786990;,
  0.335680;0.775840;,
  0.351860;0.758840;,
  0.335320;0.764380;,
  0.335350;0.753200;,
  0.352660;0.737350;,
  0.335780;0.741740;,
  0.336580;0.730600;,
  0.337790;0.719190;,
  0.423880;0.845140;,
  0.418580;0.828400;,
  0.414440;0.811330;,
  0.411490;0.794030;,
  0.409730;0.776560;,
  0.409180;0.759010;,
  0.409840;0.741460;,
  0.411700;0.724000;,
  0.414750;0.706710;,
  0.621130;0.208960;,
  0.600940;0.200600;,
  0.600940;0.230290;,
  0.580760;0.208960;,
  0.572400;0.229140;,
  0.580760;0.249330;,
  0.600940;0.257690;,
  0.621130;0.249330;,
  0.629490;0.229140;,
  0.720367;0.502478;,
  0.721093;0.552715;,
  0.674731;0.502112;,
  0.331668;0.509383;,
  0.278047;0.551326;,
  0.278533;0.514240;,
  0.719644;0.452309;,
  0.811588;0.416173;,
  0.811954;0.503700;,
  0.812277;0.580868;,
  0.999857;0.513270;,
  0.999236;0.629423;,
  1.000655;0.363059;,
  0.184569;0.581986;,
  0.185394;0.514847;,
  0.186524;0.421957;,
  0.279252;0.458963;,
  -0.000764;0.629423;,
  -0.000143;0.513270;,
  0.000655;0.363059;,
  -2.257220;2.697805;,
  -2.336640;1.821855;,
  -2.484726;1.801700;,
  -2.400961;1.165151;,
  -1.862392;0.528572;,
  -1.070830;0.643037;,
  -1.144997;0.139840;,
  -0.392487;-0.128516;,
  0.499948;0.292166;,
  0.499680;-0.336060;,
  1.340824;-0.190853;,
  2.043131;0.626053;,
  2.151983;0.064439;,
  2.832024;0.482963;,
  3.360233;1.807645;,
  3.357528;1.066855;,
  3.539926;1.784389;,
  3.268702;2.847659;;
 }
}
