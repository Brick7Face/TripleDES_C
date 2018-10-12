////////////////////////////////////////////////////////////////////////////////
//
// main.c - Easy Triple-DES
// Copyright (C) 2009  Mehter Tariq <mehtertariq@integramicro.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#include "tdes.h"

#define _MAIN_H_
#include "main.h"

int main(void) {
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
				      0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	printf("Encrypting 18 bytes of binary data to generate 24 bytes of binary data\n\n");
	tdes_encrypt(18, plain_text, encrypted_text);
	printf("Decrypting 24 bytes of binary data\n\n");
	tdes_decrypt(24, encrypted_text, plain_text);
	return 0;
}
