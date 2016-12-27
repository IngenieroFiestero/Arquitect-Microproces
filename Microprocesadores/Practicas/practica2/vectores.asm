
 	.global _c_int00
	.global _Reset
	.sect "vectores"

_Reset:	.ivec _c_int00,USE_RETA
