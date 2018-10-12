////////////////////////////////////////////////////////////////////////////////
//
// tdes8bit.c - Easy Triple-DES
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

#include "main8bit.h"

#define _TDES8BIT_H_
#include "tdes8bit.h"

void left_shift(int n, unsigned char *arr) {
	int i, j;
	for (i=0; i<n; i++) {
		temp=*(arr+0);
		*(arr+0)<<=1;
		if (((*(arr+1))&0x80)==0x80) {
			*(arr+0)|=0x01;
		}
		else {
			*(arr+0)&=0xFE;
		}
		*(arr+1)<<=1;
		if (((*(arr+2))&0x80)==0x80) {
			*(arr+1)|=0x01;
		}
		else {
			*(arr+1)&=0xFE;
		}
		*(arr+2)<<=1;
		if (((*(arr+3))&0x80)==0x80) {
			*(arr+2)|=0x01;
		}
		else {
			*(arr+2)&=0xFE;
		}
		*(arr+3)<<=1;
		if ((temp&0x80)==0x80) {
			*(arr+3)|=0x10;
		}
		else {
			*(arr+3)&=0xEF;
		}
	}
}
void print(unsigned char arr[]) {
	int i;
	for (i=0; i<8; i++) {
		printf("%3x", arr[i]);
	}
	printf("\n");
}
void tdes_init(unsigned char key_ring[3][8]) {
	int stage;
	int i, j;
	for (stage=0; stage<3; stage++) {
		for (i=0; i<16; i++) {
			for (j=0; j<6; j++) {
				k[stage][i][j]=0xAA;
			}
		}
	}
	for (stage=0; stage<3; stage++) {
		for (i=0; i<8; i++) {
			/*
			for (j=0; j<8; j++) {
				key[stage][i*8+j]=(key_ring[stage][i]&(0x01<<(7-j)))>>(7-j);
			}
			*/
			key[stage][i]=key_ring[stage][i];
		}
	}
	for (stage=0; stage<3; stage++) {
		for (i=0; i<28; i++) {
			/*
			c[i]=key[stage][pc1[i]-1];
			d[i]=key[stage][pc1[i+28]-1];
			*/
			temp=pc1[i]-1;
			if (((key[stage][temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
				c[i/8]|=(0x80>>(i%8));
			}
			else {
				c[i/8]&=(~(0x80>>(i%8)));
			}
			temp=pc1[i+28]-1;
			if (((key[stage][temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
				d[i/8]|=(0x80>>(i%8));
			}
			else {
				d[i/8]&=(~(0x80>>(i%8)));
			}
		}
		for (i=0; i<16; i++) {
			left_shift(left_shifts[i], c);
			left_shift(left_shifts[i], d);
			/*
			for (j=0; j<28; j++) {
				cd[j]=c[j];
				cd[j+28]=d[j];
			}
			*/
			cd[0]=c[0];
			cd[1]=c[1];
			cd[2]=c[2];
			cd[3]=c[3];
			cd[3]&=0xF0;
			cd[3]|=(d[0]&0xF0)>>4;
			cd[4]=(d[0]<<4)|((d[1]&0xF0)>>4);
			cd[5]=(d[1]<<4)|((d[2]&0xF0)>>4);
			cd[6]=(d[2]<<4)|((d[3]&0xF0)>>4);
			/*
			for (j=0; j<48; j++) {
				k[stage][i][j]=cd[pc2[j]-1];
			}
			*/
			for (j=0; j<48; j++) {
				temp=pc2[j]-1;
				if (((cd[temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
					k[stage][i][j/8]|=(0x80>>(j%8));
				}
				else {
					k[stage][i][j/8]&=(~(0x80>>(j%8)));
				}
			}
		}
	}
}
void des_encrypt(int stage) {
	int i, j;
	/*
	for (i=0; i<64; i++) {
	*/
	for (i=0; i<8; i++) {
		et[i]=pt[i];
	}
	for (i=0; i<64; i++) {
		/*
		perm_input[i]=et[ip[i]-1];
		*/
		temp=ip[i]-1;
		if (((et[temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
			perm_input[i/8]|=(0x80>>(i%8));
		}
		else {
			perm_input[i/8]&=(~(0x80>>(i%8)));
		}
	}
	/*
	for (i=0; i<32; i++) {
	*/
	for (i=0; i<4; i++) {
		/*
		l[i]=perm_input[i];
		r[i]=perm_input[i+32];
		*/
		l[i]=perm_input[i];
		r[i]=perm_input[i+4];
	}
	for (i=0; i<16; i++) {
		for (j=0; j<48; j++) {
			/*
			b[j]=r[e[j]-1]^k[stage-1][i][j];
			*/
			temp=e[j]-1;
			if (((r[temp/8])&(0x80>>(temp%8)))!=((k[stage-1][i][j/8])&(0x80>>(j%8)))
			   ) {
				b[j/6]|=(0x80>>(j%6));
			}
			else {
				b[j/6]&=(~(0x80>>(j%6)));
			}
		}
		for (j=0; j<8; j++) {
			/*
			row=(b[j*6+0]<<1)|(b[j*6+5]);
			col=(b[j*6+1]<<3)|(b[j*6+2]<<2)|(b[j*6+3]<<1)|b[j*6+4];
			*/
			row=((b[j]&0x80)>>6)|((b[j]&0x04)>>2);
			col=(b[j]&0x78)>>3;
			switch (j) {
			case 0:
				s_element=s1[row][col];
				break;
			case 1:
				s_element=s2[row][col];
				break;
			case 2:
				s_element=s3[row][col];
				break;
			case 3:
				s_element=s4[row][col];
				break;
			case 4:
				s_element=s5[row][col];
				break;
			case 5:
				s_element=s6[row][col];
				break;
			case 6:
				s_element=s7[row][col];
				break;
			case 7:
				s_element=s8[row][col];
				break;
			default:
				break;
			}
			/*
			s[j*4+0]=(s_element&0x08)>>3;
			s[j*4+1]=(s_element&0x04)>>2;
			s[j*4+2]=(s_element&0x02)>>1;
			s[j*4+3]=s_element&0x01;
			*/
			if ((j%2)==0) {
				s[j/2]&=0x0F;
				s[j/2]|=s_element<<4;
			}
			else {
				s[j/2]&=0xF0;
				s[j/2]|=s_element;
			}
		}
		for (j=0; j<32; j++) {
			/*
			f[j]=s[p[j]-1];
			*/
			temp=p[j]-1;
			if (((s[temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
				f[j/8]|=(0x80>>(j%8));
			}
			else {
				f[j/8]&=(~(0x80>>(j%8)));
			}
		}
		/*
		for (j=0; j<32; j++) {
			temp=r[j];
			r[j]=l[j]^f[j];
			l[j]=temp;
		*/ 
		for (j=0; j<4; j++) {
			temp=r[j];
			r[j]=l[j]^f[j];
			l[j]=temp;
		}
	}
	/*
	for (i=0; i<32; i++) {
		pre_output[i]=r[i];
		pre_output[i+32]=l[i];
	*/
	for (i=0; i<4; i++) {
		pre_output[i]=r[i];
		pre_output[i+4]=l[i];
	}
	for (i=0; i<64; i++) {
		/*
		et[i]=pre_output[ip_inv[i]-1];
		*/
		temp=ip_inv[i]-1;
		if (((pre_output[temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
			et[i/8]|=(0x80>>(i%8));
		}
		else {
			et[i/8]&=(~(0x80>>(i%8)));
		}
	}
}
void des_decrypt(int stage) {
	int i, j;
	/*
	for (i=0; i<64; i++) {
	*/
	for (i=0; i<8; i++) {
		pt[i]=et[i];
	}
	for (i=0; i<64; i++) {
		/*
		perm_input[i]=pt[ip[i]-1];
		*/
		temp=ip[i]-1;
		if (((pt[temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
			perm_input[i/8]|=(0x80>>(i%8));
		}
		else {
			perm_input[i/8]&=(~(0x80>>(i%8)));
		}
	}
	/*
	for (i=0; i<32; i++) {
	*/
	for (i=0; i<4; i++) {
		/*
		l[i]=perm_input[i];
		r[i]=perm_input[i+32];
		*/
		r[i]=perm_input[i];
		l[i]=perm_input[i+4];
	}
	for (i=16; i>0; i--) {
		for (j=0; j<48; j++) {
			/*
			b[j]=l[e[j]-1]^k[stage-1][i-1][j];
			*/
			temp=e[j]-1;
			if (((l[temp/8])&(0x80>>(temp%8)))!=((k[stage-1][i-1][j/8])&(0x80>>(j%8)))
			   ) {
				b[j/6]|=(0x80>>(j%6));
			}
			else {
				b[j/6]&=(~(0x80>>(j%6)));
			}
		}
		for (j=0; j<8; j++) {
			/*
			row=(b[j*6+0]<<1)|(b[j*6+5]);
			col=(b[j*6+1]<<3)|(b[j*6+2]<<2)|(b[j*6+3]<<1)|b[j*6+4];
			*/
			row=((b[j]&0x80)>>6)|((b[j]&0x04)>>2);
			col=(b[j]&0x78)>>3;
			switch (j) {
			case 0:
				s_element=s1[row][col];
				break;
			case 1:
				s_element=s2[row][col];
				break;
			case 2:
				s_element=s3[row][col];
				break;
			case 3:
				s_element=s4[row][col];
				break;
			case 4:
				s_element=s5[row][col];
				break;
			case 5:
				s_element=s6[row][col];
				break;
			case 6:
				s_element=s7[row][col];
				break;
			case 7:
				s_element=s8[row][col];
				break;
			default:
				break;
			}
			/*
			s[j*4+0]=(s_element&0x08)>>3;
			s[j*4+1]=(s_element&0x04)>>2;
			s[j*4+2]=(s_element&0x02)>>1;
			s[j*4+3]=s_element&0x01;
			*/
			if ((j%2)==0) {
				s[j/2]&=0x0F;
				s[j/2]|=s_element<<4;
			}
			else {
				s[j/2]&=0xF0;
				s[j/2]|=s_element;
			}
		}
		for (j=0; j<32; j++) {
			/*
			f[j]=s[p[j]-1];
			*/
			temp=p[j]-1;
			if (((s[temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
				f[j/8]|=(0x80>>(j%8));
			}
			else {
				f[j/8]&=(~(0x80>>(j%8)));
			}
		}
		/*
		for (j=0; j<32; j++) {
			temp=r[j];
			r[j]=l[j]^f[j];
			l[j]=temp;
		*/
		for (j=0; j<4; j++) {
			temp=l[j];
			l[j]=r[j]^f[j];
			r[j]=temp;
		}
	}
	/*
	for (i=0; i<32; i++) {
		pre_output[i]=r[i];
		pre_output[i+32]=l[i];
	*/
	for (i=0; i<4; i++) {
		pre_output[i]=l[i];
		/*
		pre_output[i+32]=r[i];
		*/
		pre_output[i+4]=r[i];
	}
	for (i=0; i<64; i++) {
		/*
		pt[i]=pre_output[ip_inv[i]-1];
		*/
		temp=ip_inv[i]-1;
		if (((pre_output[temp/8])&(0x80>>(temp%8)))==(0x80>>(temp%8))) {
			pt[i/8]|=(0x80>>(i%8));
		}
		else {
			pt[i/8]&=(~(0x80>>(i%8)));
		}
	}
}
void tdes_encrypt(unsigned long n, unsigned char *in, unsigned char *out) {
	unsigned long i, j, k, cnt;
	cnt=n;
	if ((n%8)!=0) {
		for (cnt=n; cnt<8*(n/8)+8; cnt++) {
			*(in+cnt)=0x00;
		}
	}
	for (i=0; i<cnt; i+=8) {
		for (j=0; j<8; j++) {
			/*
			for (k=0; k<8; k++) {
				pt[j*8+k]=((*(in+i+j))&(0x01<<(7-k)))>>(7-k);
			}
			*/
			pt[j]=*(in+i+j);
		}
		printf("\nTDES Ciphertext Block %d:\n", i/8);
		des_encrypt(1);
		des_decrypt(2);
		des_encrypt(3);
		for (j=0; j<8; j++) {
			/*
			*(out+i+j)=0x00;
			for (k=0; k<8; k++) {
				if (et[j*8+k]==0x01) {
					*(out+i+j)|=(0x01<<(7-k));
				}
				else {
					*(out+i+j)&=~(0x01<<(7-k));
				}
			}
			*/
			*(out+i+j)=et[j];
		}
		for (j=i; j<i+8; j++) {
			printf("%2x ", *(out+j));
		}
		getchar();
	}
	printf("\n\n");
}
void tdes_decrypt(unsigned long n, unsigned char *in, unsigned char *out) {
	unsigned long i, j, k, cnt;
	cnt=n;
	if ((n%8)!=0) {
		cnt=8*(n/8)+8;
	}
	for (i=0; i<cnt; i+=8) {
		for (j=0; j<8; j++) {
			/*
			for (k=0; k<8; k++) {
				et[j*8+k]=((*(in+i+j))&(0x01<<(7-k)))>>(7-k);
			}
			*/
			et[j]=*(in+i+j);
		}
		printf("\nTDES Plaintext Block %d:\n", i/8);
		des_decrypt(3);
		des_encrypt(2);
		des_decrypt(1);
		for (j=0; j<8; j++) {
			/*
			*(out+i+j)=0x00;
			for (k=0; k<8; k++) {
				if (pt[j*8+k]==0x01) {
					*(out+i+j)|=(0x01<<(7-k));
				}
				else {
					*(out+i+j)&=~(0x01<<(7-k));
				}
			}
			*/
			*(out+i+j)=pt[j];
		}
		for (j=i; j<i+8; j++) {
			printf("%2x ", *(out+j));
		}
		getchar();
	}
	printf("\n\n");
}
