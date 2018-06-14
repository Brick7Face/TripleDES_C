////////////////////////////////////////////////////////////////////////////////
//
// test.c - Easy Triple-DES
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

#include "main.h"
#include "tdes.h"

#define _MOVS_H_
#include "movs.h"

#define _TMOVS_H_
#include "tmovs.h"

#define _TEST_H_
#include "test.h"

void movs_for_des_appB_table1(void) {
	unsigned char i, j, k, result;
	unsigned char key_ring[3][8]={
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	result=1;
	for (i=0; i<64; i++) {
		for (j=0; j<8; j++) {
			for (k=0; k<8; k++) {
				pt[j*8+k]=((NISTSP800_17AppBTable1[i][j+1])&(0x01<<(7-k)))>>(7-k);
			}
		}
		pt[i]=1;
		tdes_init(key_ring);
		printf("DES Ciphertext:\n");
		des_encrypt(1);
		print(et);
		printf("DES Plaintext:\n");
		des_decrypt(1);
		print(pt);
		for (j=0; j<8; j++) {
			for (k=0; k<8; k++) {
				if (et[j*8+k]!=((NISTSP800_17AppBTable1[i][j+9])&(0x01<<(7-k)))>>(7-k)) {
					result=0;
					break;
				}
			}
			if (result==0) {
				break;
			}
		}
		getchar();
		if (result==0) {
			break;
		}
	}
	if (result==1) {
		printf("DES MOVS TEST PASSED\n");
	}
	else {
		printf("DES MOVS TEST FAILED\n");
	}
	getchar();
}
void tmovs_for_tdes_tableA_1(void) {
	unsigned char i, j, k, result;
	unsigned char key_ring[3][8]={
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}
	};
	result=1;
	for (i=0; i<64; i++) {
		for (j=0; j<8; j++) {
			for (k=0; k<8; k++) {
				pt[j*8+k]=((NISTSP800_20AppATableA_1[i][j+1])&(0x01<<(7-k)))>>(7-k);
			}
		}
		pt[i]=1;
		tdes_init(key_ring);
		printf("TDES Ciphertext:\n");
		des_encrypt(1);
		des_decrypt(2);
		des_encrypt(3);
		print(et);
		printf("TDES Plaintext:\n");
		des_decrypt(3);
		des_encrypt(2);
		des_decrypt(1);
		print(pt);
		for (j=0; j<8; j++) {
			for (k=0; k<8; k++) {
				if (et[j*8+k]!=((NISTSP800_20AppATableA_1[i][j+9])&(0x01<<(7-k)))>>(7-k)) {
					result=0;
					break;
				}
			}
			if (result==0) {
				break;
			}
		}
		getchar();
		if (result==0) {
			break;
		}
	}
	if (result==1) {
		printf("TDES TMOVS TEST PASSED\n");
	}
	else {
		printf("TDES TMOVS TEST FAILED\n");
	}
	getchar();
}
/*
int main(void) {
	unsigned char c;
	printf("Testing DES with data from MOVS for DES Appendix B - Table 1\n\n");
	movs_for_des_appB_table1();
	printf("Testing DES with data from TMOVS for TDES Appendix A - Table A.1\n\n");	
	tmovs_for_tdes_tableA_1();
	return 0;
}
*/
