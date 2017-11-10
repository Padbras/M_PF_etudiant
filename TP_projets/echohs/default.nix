{ pkgs ? import <nixpkgs> {} }:
pkgs.haskellPackages.callPackage ./echohs.nix {}

