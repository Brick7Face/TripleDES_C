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
#include <stdlib.h>

#include "tdes.h"

#define _MAIN_H_
#include "main.h"

/* ---------------------------- MR ONE --------------------------------------- */

//using different key to decrypt cipher should NOT equal original plaintext
void test_one_one(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.1------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08},
			{0xaa, 0xcc, 0xff, 0x0c, 0x01, 0x01, 0x01, 0x2b},
			{0xab, 0x00, 0x01, 0x01, 0x01, 0x7e, 0x3f, 0x1a}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//test a key similar to the real key with front ASCII value changed, should not be same
void test_one_two(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.2------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x10, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//test a key similar to the real key with front ASCII value increased by 1, should not be same
void test_one_three(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.3------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//test a key similar to the real key with back ASCII value changed, should not be same
void test_one_four(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.4------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x10}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//test a key similar to the real key with back ASCII value increased by 1, should not be same
void test_one_five(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.5------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//repeat 1.1 with a different plaintext
void test_one_six(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.6------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x40, 0x30, 0x20},
			{0xAF, 0xAA, 0xFF, 0x01, 0x01, 0x01, 0x00, 0x10},
			{0xBB, 0xCB, 0xCA, 0xAE, 0xEE, 0x01, 0xDD, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//repeat 1.2 with a different plaintext
void test_one_seven(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.7------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x10, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//repeat 1.3 with a different plaintext
void test_one_eight(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.8------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//repeat 1.4 with a different plaintext
void test_one_nine(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.9------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x10}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//repeat 1.5 with a different plaintext
void test_one_ten(FILE* file) {
	fprintf(file, "\r\n------Testing MR 1.10------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02}
	};
	tdes_init(key_ring);
	//fprintf(file, "\r\nEncrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	//fprintf(file, "\r\nDecrypting 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_init(key_ring2);
	//fprintf(file, "\r\nSecond plaintext\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

/* ---------------------------- MR TWO --------------------------------------- */

//tests that two slightly different plaintexts don't generate similar cipher - this does due to similar blocks
void test_two_one(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.1------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char plain_text2[32]={0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text2, encrypted_text);
}

//same as first but decreased
void test_two_two(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.2------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char plain_text2[32]={0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text2, encrypted_text);
}

//using similar cipher should not decrypt to string similar
void test_two_three(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.3------\r\n\r\n");
	unsigned char plain_text[32];
	unsigned char encrypted_text[32]={0xaa, 0xbc, 0xde, 0xff, 0x10, 0x09, 0x80, 0x70,
			0x06, 0x01, 0x02, 0x03, 0x04, 0x05, 0x16, 0x07,
			0x1a, 0x1b};
	unsigned char encrypted_text2[32]={0xbc, 0xaa, 0xde, 0xff, 0x10, 0x09, 0x80, 0x70,
			0x06, 0x02, 0x02, 0x03, 0x04, 0x05, 0x16, 0x49,
			0x1a, 0x1b};
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_decrypt(file, 24, encrypted_text2, plain_text);
}

//same as 2.3 but different cipher
void test_two_four(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.4------\r\n\r\n");
	unsigned char plain_text[32];
	unsigned char encrypted_text[32]={0x01, 0xaa, 0xaa, 0xff, 0xbb, 0xcc, 0x80, 0x70,
			0xb6, 0x01, 0xc2, 0xa3, 0x04, 0x05, 0x16, 0xd7,
			0xdf, 0xee};
	unsigned char encrypted_text2[32]={0xaa, 0x01, 0xaa, 0xff, 0xbb, 0xcc, 0x80, 0x70,
			0xb6, 0x01, 0x2c, 0xa3, 0x04, 0x05, 0x16, 0xd7,
			0xdf, 0xee};
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_decrypt(file, 24, encrypted_text2, plain_text);
}

//encrypt random string, get cipher and change, decrypt, compare string original, should not be equal
void test_two_five(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.5------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char encrypted_text2[32]={0xe1, 0x73, 0x38, 0x7b, 0xc2, 0xd1, 0xbe, 0x4f,
			0x2c, 0xd4, 0xe5, 0x96, 0xe5, 0xdf, 0xd0, 0xe2,
			0x33, 0x69};
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_decrypt(file, 24, encrypted_text2, plain_text);
}

//same as first test but different plaintexts
void test_two_six(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.6------\r\n\r\n");
	unsigned char plain_text[32]={0x93, 0x01, 0x02, 0x03, 0x04, 0x05, 0x55, 0x07,
			0x1F, 0x2A, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x30,
			0xFA, 0xBB};
	unsigned char plain_text2[32]={0x94, 0x01, 0x02, 0x03, 0x04, 0x05, 0x55, 0x07,
			0x1F, 0x2A, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x30,
			0xFA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text2, encrypted_text);
}

//same as 2.6 but decreased
void test_two_seven(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.7------\r\n\r\n");
	unsigned char plain_text[32]={0x93, 0x01, 0x02, 0x03, 0x04, 0x05, 0x55, 0x07,
			0x1F, 0x2A, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x30,
			0xFA, 0xBB};
	unsigned char plain_text2[32]={0x92, 0x01, 0x02, 0x03, 0x04, 0x05, 0x55, 0x07,
			0x1F, 0x2A, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x30,
			0xFA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text2, encrypted_text);
}

//using similar cipher should not decrypt to string with similar to test
void test_two_eight(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.8------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char encrypted_text2[32]={0x94, 0xf7, 0xa5, 0xe5, 0xdd, 0x31, 0xd9, 0x00,
			0x49, 0x1e, 0x89, 0x0d, 0xe9, 0xac, 0xe9, 0x32,
			0x45, 0x91};
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_decrypt(file, 24, encrypted_text2, plain_text);
}

//similar to last test but cipher is decreased by 1
void test_two_nine(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.9------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char encrypted_text2[32]={0x96, 0xf7, 0xa5, 0xe5, 0xdd, 0x31, 0xd9, 0x00,
			0x49, 0x1e, 0x89, 0x0d, 0xe9, 0xac, 0xe9, 0x32,
			0x45, 0x91};
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_decrypt(file, 24, encrypted_text2, plain_text);
}

//randomly generate cipher, get decryption, change cipher by 1 character, decrypt, compare both decryptions
void test_two_ten(FILE* file) {
	fprintf(file, "\r\n------Testing MR 2.10------\r\n\r\n");
	unsigned char plain_text[32];
	unsigned char encrypted_text[32]={0x96, 0xf7, 0xa5, 0xe5, 0xdd, 0x31, 0xd9, 0x00,
			0x49, 0x1e, 0x89, 0x0d, 0xe9, 0xbd, 0xe9, 0x32,
			0x45, 0x91};
	unsigned char encrypted_text2[32]={0x96, 0xf7, 0xa5, 0xe5, 0xdd, 0x31, 0xd9, 0x00,
			0x49, 0x1e, 0x89, 0x0d, 0xe9, 0xac, 0xe9, 0x32,
			0x45, 0x91};
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_decrypt(file, 24, encrypted_text2, plain_text);
}

/* ---------------------------- MR THREE --------------------------------------- */

//using different key to encrypt same plaintext should not result in same ciphertext
void test_three_one(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.1------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x40, 0x30, 0x20},
			{0xAF, 0xAA, 0xFF, 0x01, 0x01, 0x01, 0x00, 0x10},
			{0xBB, 0xCB, 0xCA, 0xAE, 0xEE, 0x01, 0xDD, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//test a key similar to the real key with front ASCII value different, should not be same
void test_three_two(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.2------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x10, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//test a key similar to the real key with front ASCII value increased by 1, should not be same
void test_three_three(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.3------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//test a key similar to the real key with back ASCII value different, should not be same
void test_three_four(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.4------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x10}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//test a key similar to the real key with back ASCII value increased by 1, should not be same
void test_three_five(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.5------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//generate and encrypt random string, use different key to decrypt, and make sure they are not equal
void test_three_six(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.6------\r\n\r\n");
	unsigned char plain_text[32]={0x93, 0x01, 0x02, 0x03, 0x04, 0x05, 0x55, 0x07,
			0x1F, 0x2A, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x30,
			0xFA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x40, 0x30, 0x20},
			{0xAF, 0xAA, 0xFF, 0x01, 0x01, 0x01, 0x00, 0x10},
			{0xBB, 0xCB, 0xCA, 0xAE, 0xEE, 0x01, 0xDD, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_decrypt(file, 24, encrypted_text, plain_text);
}

//generate and decrypt random string, use different key to encrypt, and make sure they are not equal
void test_three_seven(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.7------\r\n\r\n");
	unsigned char plain_text[32];
	unsigned char encrypted_text[32]={0x93, 0x01, 0x02, 0x03, 0x04, 0x05, 0x55, 0x07,
			0x1F, 0x2A, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x30,
			0xFA, 0xBB};
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x40, 0x30, 0x20},
			{0xAF, 0xAA, 0xFF, 0x01, 0x01, 0x01, 0x00, 0x10},
			{0xBB, 0xCB, 0xCA, 0xAE, 0xEE, 0x01, 0xDD, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n\r\n");
	tdes_decrypt(file, 24, encrypted_text, plain_text);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//repeat 3.1 with a different plaintext
void test_three_eight(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.8------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x40, 0x30, 0x20},
			{0xAF, 0xAA, 0xFF, 0x01, 0x01, 0x01, 0x00, 0x10},
			{0xBB, 0xCB, 0xCA, 0xAE, 0xEE, 0x01, 0xDD, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//repeat 3.2 with different plaintext
void test_three_nine(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.9------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x10, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//repeat 3.3 with different plaintext
void test_three_ten(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.10------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//repeat 3.4 with different plaintext
void test_three_eleven(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.11------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x10}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//repeat 3.5 with different plaintext
void test_three_twelve(FILE* file) {
	fprintf(file, "\r\n------Testing MR 3.12------\r\n\r\n");
	unsigned char plain_text[32]={0x91, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1F, 0x2E, 0x3D, 0x4C, 0x5B, 0x6A, 0x70, 0x00,
			0xAA, 0xBB};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02}
	};
	tdes_init(key_ring);
	//fprintf(file, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_init(key_ring2);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

/* ---------------------------- MR FOUR --------------------------------------- */

//generate cipher twice and compare; should be the same
void test_four_one(FILE* file) {
	fprintf(file, "\r\n------Testing MR 4.1------\r\n\r\n");
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
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//generate cipher from different words and compare; should be different
void test_four_two(FILE* file) {
	fprintf(file, "\r\n------Testing MR 4.2------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char plain_text2[32]={0x1B, 0x1A, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text2, encrypted_text);
}

//generate cipher from different words and compare and then original and compare 1st
//and 3rd; should be same
void test_four_three(FILE* file) {
	fprintf(file, "\r\n------Testing MR 4.3------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char plain_text2[32]={0x1B, 0x1A, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	tdes_init(key_ring);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text2, encrypted_text);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//generate cipher 5 times and compare 1st and last; should be same
void test_four_four(FILE* file) {
	fprintf(file, "\r\n------Testing MR 4.4------\r\n\r\n");
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
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
	tdes_encrypt(file, 18, plain_text, encrypted_text);
}

//test to cover one untested code block in tdes.c
void last_test(FILE* file) {
	fprintf(file, "\r\n------Finshing Up------\r\n\r\n");
	unsigned char plain_text[32]={0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
			0x1A, 0x1B};
	unsigned char encrypted_text[32];
	unsigned char key_ring[3][8]={
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
			{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	unsigned char key_ring2[3][8]={
			{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08},
			{0xaa, 0xcc, 0xff, 0x0c, 0x01, 0x01, 0x01, 0x2b},
			{0xab, 0x00, 0x01, 0x01, 0x01, 0x7e, 0x3f, 0x1a}
	};
	tdes_init(key_ring);
	tdes_encrypt(file, 17, plain_text, encrypted_text);
	tdes_decrypt(file, 13, encrypted_text, plain_text);
	unsigned char arr[5]={'a', 'b', 'c', 'd', 'e'};
	print(file, arr);
}



//do everything correctly, then run tests
int main(void) {
	FILE* f = fopen("output.txt", "a");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
/*
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
	fprintf(f, "Encrypting 18 bytes of binary data to generate 24 bytes of binary data\r\n");
	tdes_encrypt(f, 18, plain_text, encrypted_text);
	fprintf(f, "Decrypting 24 bytes of binary data\r\n");
	tdes_decrypt(f, 24, encrypted_text, plain_text);
*/
	test_one_one(f);
	test_one_two(f);
	test_one_three(f);
	test_one_four(f);
	test_one_five(f);
	test_one_six(f);
	test_one_seven(f);
	test_one_eight(f);
	test_one_nine(f);
	test_one_ten(f);

	test_two_one(f);
	test_two_two(f);
	test_two_three(f);
	test_two_four(f);
	test_two_five(f);
	test_two_six(f);
	test_two_seven(f);
	test_two_eight(f);
	test_two_nine(f);
	test_two_ten(f);

	test_three_one(f);
	test_three_two(f);
	test_three_three(f);
	test_three_four(f);
	test_three_five(f);
	test_three_six(f);
	test_three_seven(f);
	test_three_eight(f);
	test_three_nine(f);
	test_three_ten(f);
	test_three_eleven(f);
	test_three_twelve(f);

	test_four_one(f);
	test_four_two(f);
	test_four_three(f);
	test_four_four(f);

	last_test(f);

	return 0;
}



