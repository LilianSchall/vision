with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "env";
  nativeBuildInputs = [ 
    pkg-config
    cmake
    valgrind
  ];
  buildInputs = [
    SDL2
  ];
}

