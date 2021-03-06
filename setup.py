import setuptools
from distutils.core import setup, Extension


sperocoin_x13_hash_module = Extension('sperocoin_x13_hash',
                               sources = ['x13module.c',
                                          'x13.c',
					  'sha3/aes_helper.c',
					  'sha3/blake.c',
					  'sha3/bmw.c',
					  'sha3/groestl.c',
					  'sha3/jh.c',
					  'sha3/keccak.c',
					  'sha3/skein.c',
					  'sha3/cubehash.c',
					  'sha3/echo.c',
					  'sha3/luffa.c',
					  'sha3/simd.c',
                                          'sha3/hamsi.c',
                                          'sha3/hamsi_helper.c',
                                          'sha3/fugue.c',
					  'sha3/shavite.c'],

                               include_dirs=['.', './sha3'])

setup (name = 'sperocoin-x13-hash',
       version = '1.0.6',
       description = 'Bindings for proof of work used by x13',
       ext_modules = [sperocoin_x13_hash_module],
       url="https://github.com/DigitalCoin1/sperocoin-x13-hash")

