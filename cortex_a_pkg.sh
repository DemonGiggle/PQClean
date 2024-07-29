#!/bin/bash


rm -rf pkgs
mkdir -p pkgs/dilithium5

cp -r crypto_sign/dilithium5/aarch64 pkgs/dilithium5
cp -r crypto_sign/dilithium5/clean pkgs/dilithium5
cp crypto_sign/dilithium5/META.yml pkgs/dilithium5

mkdir pkgs/dilithium5/aarch64/keccak2x
mkdir pkgs/dilithium5/clean/keccak2x


cp  common/fips202.c        \
	common/fips202.h        \
	common/randombytes.h    \
	pkgs/dilithium5/aarch64

cp  common/fips202.c        \
	common/fips202.h        \
	common/randombytes.h    \
	pkgs/dilithium5/clean

cp	common/keccak2x/fips202x2.c \
	common/keccak2x/fips202x2.h \
	pkgs/dilithium5/aarch64/keccak2x

cp common/fips202.c \
	common/fips202.h \
	common/keccak2x/fips202x2.c \
	common/keccak2x/fips202x2.h \
	pkgs/dilithium5/clean/keccak2x

echo "Now, copy pkgs/ content to appropriate place"
