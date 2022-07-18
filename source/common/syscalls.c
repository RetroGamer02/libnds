#include <nds/ndstypes.h>
#include <nds/system.h>
#include <nds/bios.h>

int swiDecompressLZSSVram(const void * source, void * destination, uint32 toGetSize, const TDecompressionStream * stream) {

	if (isDSiMode()) {
		return swiDecompressLZSSVramTWL(source,destination,toGetSize,stream);
	} else {
		return swiDecompressLZSSVramNTR(source,destination,toGetSize,stream);
	}
	
}
