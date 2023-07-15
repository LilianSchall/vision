with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "env";
  nativeBuildInputs = [ 
    pkg-config
    cmake
  ];
  buildInputs = [
    SDL2
  ];
}

