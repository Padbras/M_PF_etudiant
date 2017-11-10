with import <nixpkgs> {};
( haskellPackages.callPackage ./echohs.nix {} ).env
