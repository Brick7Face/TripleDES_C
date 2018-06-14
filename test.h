////////////////////////////////////////////////////////////////////////////////
//
// test.h - Easy Triple-DES
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
#ifdef _TEST_H_
////////////////////////////////////////////////////////////////////////////////
void movs_for_des_appB_table1(void);
void tmovs_for_tdes_tableA_1(void);
////////////////////////////////////////////////////////////////////////////////
#else
////////////////////////////////////////////////////////////////////////////////
extern void movs_for_des_appB_table1(void);
extern void tmovs_for_tdes_tableA_1(void);
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
