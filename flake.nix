{
  description = "calculator development environment";
  inputs = { nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable"; };
  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};

    in {
      devShells.${system}.default = with pkgs;
        mkShell {
          buildInputs = [
            premake5
            clang
            ninja
            pkg-config
            nixfmt
            mesa
            mesa.drivers
            libGL
            alsa-lib
            pulseaudio
            libvorbis
            libogg
            cmake
            bear
          ] ++ (with pkgs.xorg; [
            libpthreadstubs
            libX11.dev
            libXrandr.dev
            libXinerama.dev
            libXcursor.dev
            libXi.dev
          ]);
        };
    };
}
