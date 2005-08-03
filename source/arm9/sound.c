/*---------------------------------------------------------------------------------
	$Id: sound.c,v 1.1 2005-08-03 05:28:07 wntrmute Exp $

	Sound Functions

	Copyright (C) 2005
		Dave Murphy (WinterMute)

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any
	damages arising from the use of this software.

	Permission is granted to anyone to use this software for any
	purpose, including commercial applications, and to alter it and
	redistribute it freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you
		must not claim that you wrote the original software. If you use
		this software in a product, an acknowledgment in the product
		documentation would be appreciated but is not required.
	2.	Altered source versions must be plainly marked as such, and
		must not be misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source
		distribution.

	$Log: not supported by cvs2svn $

---------------------------------------------------------------------------------*/
#include <nds/arm9/sound.h>
#include <nds/arm9/cache.h>
#include <string.h>

//---------------------------------------------------------------------------------
void playSoundBlock(TransferSound *snd) {
//---------------------------------------------------------------------------------
	DC_FlushRange( snd, sizeof(TransferSound) );

	IPC->soundData = snd;
}

//---------------------------------------------------------------------------------
static TransferSound Snd = 
//---------------------------------------------------------------------------------
{
	{
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 },
		{ (void *)0 , 0, 11025, 64, 64, 1 }
	}
};

//---------------------------------------------------------------------------------
void setGenericSound( u32 rate, u8 vol, u8 pan, u8 format) {
//---------------------------------------------------------------------------------

	Snd.data[0].rate	= rate;
	Snd.data[0].vol		= vol;
	Snd.data[0].pan		= pan;
	Snd.data[0].format	= format;
}

//---------------------------------------------------------------------------------
void playSound( pTransferSoundData sound) {
//---------------------------------------------------------------------------------
	Snd.count = 1;

	memcpy( &Snd.data[0], sound, sizeof(TransferSoundData) );

	playSoundBlock(&Snd);

}

//---------------------------------------------------------------------------------
void playGenericSound(const void* data, u32 length) {
//---------------------------------------------------------------------------------
	
	Snd.count = 1;
	Snd.data[0].data = data;
	Snd.data[0].len = length;

	playSoundBlock(&Snd);
}
