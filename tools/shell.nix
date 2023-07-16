with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "env";
  hardeningDisable = ["all"];
  nativeBuildInputs = [ 
    pkg-config
    cmake
    valgrind
  ];
  buildInputs = [
    SDL2
    gdb
  ];
}

