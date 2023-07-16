// rotatevideo_lcd用グラフィックライブラリ　by K.Tanaka
// 画面上部の固定表示領域対応

#include "rotatevideo_lcd.h"

const unsigned char FontData[256*8]={
//フォントデータ、キャラクタコード順に8バイトずつ、上位ビットが左
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x08,0x0C,0xFE,0xFE,0x0C,0x08,0x00,
	0x00,0x20,0x60,0xFE,0xFE,0x60,0x20,0x00,
	0x18,0x3C,0x7E,0x18,0x18,0x18,0x18,0x00,
	0x00,0x18,0x18,0x18,0x18,0x7E,0x3C,0x18,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x30,0x30,0x30,0x30,0x00,0x00,0x30,0x00,
	0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00,
	0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00,
	0x18,0x7E,0xD8,0x7E,0x1A,0xFE,0x18,0x00,
	0xE0,0xE6,0x0C,0x18,0x30,0x6E,0xCE,0x00,
	0x78,0xCC,0xD8,0x70,0xDE,0xCC,0x76,0x00,
	0x0C,0x18,0x30,0x00,0x00,0x00,0x00,0x00,
	0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00,
	0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00,
	0xD6,0x7C,0x38,0xFE,0x38,0x7C,0xD6,0x00,
	0x00,0x30,0x30,0xFC,0x30,0x30,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x60,
	0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x38,0x38,0x00,
	0x00,0x06,0x0C,0x18,0x30,0x60,0xC0,0x00,
	0x7C,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00,
	0x18,0x38,0x78,0x18,0x18,0x18,0x7E,0x00,
	0x7C,0xC6,0x06,0x1C,0x70,0xC0,0xFE,0x00,
	0x7C,0xC6,0x06,0x3C,0x06,0xC6,0x7C,0x00,
	0x0C,0x1C,0x3C,0x6C,0xFE,0x0C,0x0C,0x00,
	0xFE,0xC0,0xF8,0x0C,0x06,0xCC,0x78,0x00,
	0x3C,0x60,0xC0,0xFC,0xC6,0xC6,0x7C,0x00,
	0xFE,0xC6,0x0C,0x18,0x30,0x30,0x30,0x00,
	0x7C,0xC6,0xC6,0x7C,0xC6,0xC6,0x7C,0x00,
	0x7C,0xC6,0xC6,0x7E,0x06,0x0C,0x78,0x00,
	0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x00,
	0x00,0x30,0x00,0x00,0x00,0x30,0x30,0x60,
	0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x00,
	0x00,0x00,0xFE,0x00,0xFE,0x00,0x00,0x00,
	0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00,
	0x7C,0xC6,0x06,0x1C,0x30,0x00,0x30,0x00,
	0x3C,0x66,0xDE,0xF6,0xDC,0x60,0x3E,0x00,
	0x38,0x6C,0xC6,0xFE,0xC6,0xC6,0xC6,0x00,
	0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00,
	0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C,0x00,
	0xF8,0x6C,0x66,0x66,0x66,0x6C,0xF8,0x00,
	0xFE,0xC0,0xC0,0xF8,0xC0,0xC0,0xFE,0x00,
	0xFE,0xC0,0xC0,0xF8,0xC0,0xC0,0xC0,0x00,
	0x3C,0x66,0xC0,0xCE,0xC6,0x66,0x3C,0x00,
	0xC6,0xC6,0xC6,0xFE,0xC6,0xC6,0xC6,0x00,
	0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,
	0x1E,0x0C,0x0C,0x0C,0x0C,0xCC,0x78,0x00,
	0xC6,0xCC,0xD8,0xF0,0xD8,0xCC,0xC6,0x00,
	0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFE,0x00,
	0xC6,0xEE,0xFE,0xD6,0xC6,0xC6,0xC6,0x00,
	0xC6,0xE6,0xF6,0xDE,0xCE,0xC6,0xC6,0x00,
	0x38,0x6C,0xC6,0xC6,0xC6,0x6C,0x38,0x00,
	0xFC,0xC6,0xC6,0xFC,0xC0,0xC0,0xC0,0x00,
	0x38,0x6C,0xC6,0xC6,0xDE,0x6C,0x3E,0x00,
	0xFC,0xC6,0xC6,0xFC,0xD8,0xCC,0xC6,0x00,
	0x7C,0xC6,0xC0,0x7C,0x06,0xC6,0x7C,0x00,
	0x7E,0x18,0x18,0x18,0x18,0x18,0x18,0x00,
	0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,0x7C,0x00,
	0xC6,0xC6,0xC6,0x6C,0x6C,0x38,0x38,0x00,
	0xC6,0xC6,0xC6,0xD6,0xFE,0xEE,0xC6,0x00,
	0xC6,0xC6,0x6C,0x38,0x6C,0xC6,0xC6,0x00,
	0xCC,0xCC,0xCC,0x78,0x30,0x30,0x30,0x00,
	0xFE,0x06,0x0C,0x38,0x60,0xC0,0xFE,0x00,
	0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00,
	0xCC,0xCC,0x78,0xFC,0x30,0xFC,0x30,0x00,
	0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00,
	0x30,0x78,0xCC,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x7C,0x0C,0x7C,0xCC,0x7E,0x00,
	0xC0,0xC0,0xFC,0xE6,0xC6,0xE6,0xFC,0x00,
	0x00,0x00,0x7C,0xC6,0xC0,0xC6,0x7C,0x00,
	0x06,0x06,0x7E,0xCE,0xC6,0xCE,0x7E,0x00,
	0x00,0x00,0x7C,0xC6,0xFE,0xC0,0x7C,0x00,
	0x1C,0x36,0x30,0xFC,0x30,0x30,0x30,0x00,
	0x00,0x00,0x7E,0xCE,0xCE,0x7E,0x06,0x7C,
	0xC0,0xC0,0xFC,0xE6,0xC6,0xC6,0xC6,0x00,
	0x18,0x00,0x38,0x18,0x18,0x18,0x3C,0x00,
	0x0C,0x00,0x1C,0x0C,0x0C,0x0C,0xCC,0x78,
	0xC0,0xC0,0xCC,0xD8,0xF0,0xF8,0xCC,0x00,
	0x38,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,
	0x00,0x00,0xFC,0xB6,0xB6,0xB6,0xB6,0x00,
	0x00,0x00,0xFC,0xE6,0xC6,0xC6,0xC6,0x00,
	0x00,0x00,0x7C,0xC6,0xC6,0xC6,0x7C,0x00,
	0x00,0x00,0xFC,0xE6,0xE6,0xFC,0xC0,0xC0,
	0x00,0x00,0x7E,0xCE,0xCE,0x7E,0x06,0x06,
	0x00,0x00,0xDC,0xE6,0xC0,0xC0,0xC0,0x00,
	0x00,0x00,0x7E,0xC0,0x7C,0x06,0xFC,0x00,
	0x30,0x30,0xFC,0x30,0x30,0x36,0x1C,0x00,
	0x00,0x00,0xC6,0xC6,0xC6,0xCE,0x76,0x00,
	0x00,0x00,0xC6,0xC6,0xC6,0x6C,0x38,0x00,
	0x00,0x00,0x86,0xB6,0xB6,0xB6,0xFC,0x00,
	0x00,0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00,
	0x00,0x00,0xC6,0xC6,0xCE,0x7E,0x06,0x7C,
	0x00,0x00,0xFE,0x0C,0x38,0x60,0xFE,0x00,
	0x3C,0x60,0x60,0xC0,0x60,0x60,0x3C,0x00,
	0x30,0x30,0x00,0x00,0x00,0x30,0x30,0x00,
	0xF0,0x18,0x18,0x0C,0x18,0x18,0xF0,0x00,
	0x60,0xB6,0x1C,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
	0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,
	0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,
	0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,
	0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
	0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
	0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
	0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,
	0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,
	0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,
	0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,
	0x18,0x18,0x18,0x18,0xFF,0x18,0x18,0x18,
	0x18,0x18,0x18,0x18,0xFF,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xFF,0x18,0x18,0x18,
	0x18,0x18,0x18,0x18,0xF8,0x18,0x18,0x18,
	0x18,0x18,0x18,0x18,0x1F,0x18,0x18,0x18,
	0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,
	0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
	0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
	0x00,0x00,0x00,0x00,0x1F,0x18,0x18,0x18,
	0x00,0x00,0x00,0x00,0xF8,0x18,0x18,0x18,
	0x18,0x18,0x18,0x18,0x1F,0x00,0x00,0x00,
	0x18,0x18,0x18,0x18,0xF8,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x07,0x0C,0x18,0x18,
	0x00,0x00,0x00,0x00,0xE0,0x30,0x18,0x18,
	0x18,0x18,0x18,0x0C,0x07,0x00,0x00,0x00,
	0x18,0x18,0x18,0x30,0xE0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x78,0x68,0x78,0x00,
	0x78,0x60,0x60,0x60,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x18,0x18,0x18,0x78,0x00,
	0x00,0x00,0x00,0x00,0x60,0x30,0x18,0x00,
	0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,
	0xFE,0x06,0x06,0xFE,0x06,0x0C,0x78,0x00,
	0x00,0x00,0xFC,0x0C,0x38,0x30,0x60,0x00,
	0x00,0x00,0x0C,0x18,0x38,0x78,0x18,0x00,
	0x00,0x00,0x30,0xFC,0xCC,0x0C,0x38,0x00,
	0x00,0x00,0x00,0xFC,0x30,0x30,0xFC,0x00,
	0x00,0x00,0x18,0xFC,0x38,0x78,0xD8,0x00,
	0x00,0x00,0x60,0xFC,0x6C,0x68,0x60,0x00,
	0x00,0x00,0x00,0x78,0x18,0x18,0xFC,0x00,
	0x00,0x00,0x7C,0x0C,0x7C,0x0C,0x7C,0x00,
	0x00,0x00,0x00,0xAC,0xAC,0x0C,0x38,0x00,
	0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,
	0xFE,0x06,0x06,0x34,0x38,0x30,0x60,0x00,
	0x06,0x0C,0x18,0x38,0x78,0xD8,0x18,0x00,
	0x18,0xFE,0xC6,0xC6,0x06,0x0C,0x38,0x00,
	0x00,0x7E,0x18,0x18,0x18,0x18,0x7E,0x00,
	0x18,0xFE,0x18,0x38,0x78,0xD8,0x18,0x00,
	0x30,0xFE,0x36,0x36,0x36,0x36,0x6C,0x00,
	0x18,0x7E,0x18,0x7E,0x18,0x18,0x18,0x00,
	0x3E,0x66,0xC6,0x0C,0x18,0x30,0xE0,0x00,
	0x60,0x7E,0xD8,0x18,0x18,0x18,0x30,0x00,
	0x00,0xFE,0x06,0x06,0x06,0x06,0xFE,0x00,
	0x6C,0xFE,0x6C,0x0C,0x0C,0x18,0x30,0x00,
	0x00,0xF0,0x00,0xF6,0x06,0x0C,0xF8,0x00,
	0xFE,0x06,0x0C,0x18,0x38,0x6C,0xC6,0x00,
	0x60,0xFE,0x66,0x6C,0x60,0x60,0x3E,0x00,
	0xC6,0xC6,0x66,0x06,0x0C,0x18,0xF0,0x00,
	0x3E,0x66,0xE6,0x3C,0x18,0x30,0xE0,0x00,
	0x0C,0x78,0x18,0xFE,0x18,0x18,0xF0,0x00,
	0x00,0xD6,0xD6,0xD6,0x0C,0x18,0xF0,0x00,
	0x7C,0x00,0xFE,0x18,0x18,0x30,0x60,0x00,
	0x30,0x30,0x38,0x3C,0x36,0x30,0x30,0x00,
	0x18,0x18,0xFE,0x18,0x18,0x30,0x60,0x00,
	0x00,0x7C,0x00,0x00,0x00,0x00,0xFE,0x00,
	0x00,0x7E,0x06,0x6C,0x18,0x36,0x60,0x00,
	0x18,0x7E,0x0C,0x18,0x3C,0x7E,0x18,0x00,
	0x06,0x06,0x06,0x0C,0x18,0x30,0x60,0x00,
	0x30,0x18,0x0C,0xC6,0xC6,0xC6,0xC6,0x00,
	0xC0,0xC0,0xFE,0xC0,0xC0,0xC0,0x7E,0x00,
	0x00,0xFE,0x06,0x06,0x0C,0x18,0x70,0x00,
	0x00,0x30,0x78,0xCC,0x06,0x06,0x00,0x00,
	0x18,0x18,0xFE,0x18,0xDB,0xDB,0x18,0x00,
	0xFE,0x06,0x06,0x6C,0x38,0x30,0x18,0x00,
	0x00,0x3C,0x00,0x3C,0x00,0x7C,0x06,0x00,
	0x0C,0x18,0x30,0x60,0xCC,0xFC,0x06,0x00,
	0x02,0x36,0x3C,0x18,0x3C,0x6C,0xC0,0x00,
	0x00,0xFE,0x30,0xFE,0x30,0x30,0x3E,0x00,
	0x30,0x30,0xFE,0x36,0x3C,0x30,0x30,0x00,
	0x00,0x78,0x18,0x18,0x18,0x18,0xFE,0x00,
	0xFE,0x06,0x06,0xFE,0x06,0x06,0xFE,0x00,
	0x7C,0x00,0xFE,0x06,0x0C,0x18,0x30,0x00,
	0xC6,0xC6,0xC6,0x06,0x06,0x0C,0x38,0x00,
	0x6C,0x6C,0x6C,0x6E,0x6E,0x6C,0xC8,0x00,
	0x60,0x60,0x60,0x66,0x6C,0x78,0x70,0x00,
	0x00,0xFE,0xC6,0xC6,0xC6,0xC6,0xFE,0x00,
	0x00,0xFE,0xC6,0xC6,0x06,0x0C,0x38,0x00,
	0x00,0xF0,0x06,0x06,0x0C,0x18,0xF0,0x00,
	0x18,0xCC,0x60,0x00,0x00,0x00,0x00,0x00,
	0x70,0xD8,0x70,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,
	0x18,0x18,0x1F,0x18,0x18,0x1F,0x18,0x18,
	0x18,0x18,0xFF,0x18,0x18,0xFF,0x18,0x18,
	0x18,0x18,0xF8,0x18,0x18,0xF8,0x18,0x18,
	0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,
	0x80,0xC0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,
	0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x01,
	0xFF,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,
	0x10,0x38,0x7C,0xFE,0xFE,0x38,0x7C,0x00,
	0x6C,0xFE,0xFE,0xFE,0x7C,0x38,0x10,0x00,
	0x10,0x38,0x7C,0xFE,0x7C,0x38,0x10,0x00,
	0x38,0x38,0xFE,0xFE,0xD6,0x10,0x7C,0x00,
	0x00,0x3C,0x7E,0x7E,0x7E,0x7E,0x3C,0x00,
	0x00,0x7C,0xC6,0xC6,0xC6,0xC6,0x7C,0x00,
	0x03,0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,
	0x80,0xC0,0x60,0x30,0x18,0x0C,0x06,0x03,
	0x83,0xC6,0x6C,0x38,0x38,0x6C,0xC6,0x83,
	0xFE,0xB6,0xB6,0xFE,0x86,0x86,0x86,0x00,
	0xC0,0xFE,0xD8,0x7E,0x58,0xFE,0x18,0x00,
	0x7E,0x66,0x7E,0x66,0x7E,0x66,0xC6,0x00,
	0xFE,0xC6,0xC6,0xFE,0xC6,0xC6,0xFE,0x00,
	0x06,0xEF,0xA6,0xFF,0xA2,0xFF,0x0A,0x06,
	0x00,0x38,0x6C,0xC6,0x7C,0x34,0x6C,0x00,
	0xFC,0x6C,0xFE,0x6E,0xF6,0xEC,0x6C,0x78,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

void pset(int x,int y,unsigned char c)
// (x,y)の位置にカラーcで点を描画
{
	if(x<0 || x>=VRAM_X) return;
	if(y<0 || y>=VRAM_Y) return;
	*(VRAM+y*VRAM_X+x)=c;
}
void pset_fixarea(int x,int y,unsigned char c)
// 画面上部固定領域(x,y)の位置にカラーcで点を描画
{
	if(x<0 || x>=VRAM_X) return;
	if(y<0 || y>=TOPLINE) return;
	*(TOPVRAM+y*VRAM_X+x)=c;
}

void putbmpmn(int x,int y,unsigned char m,unsigned char n,const unsigned char bmp[])
// 横m*縦nドットのキャラクターを座標x,yに表示
// unsigned char bmp[m*n]配列に、単純にカラー番号を並べる
// カラー番号が0の部分は透明色として扱う
{
	int i,j;
	unsigned char *vp;
	const unsigned char *p;
	if(x<=-m || x>VRAM_X || y<=-n || y>=VRAM_Y) return; //画面外
	if(y<0){ //画面上部に切れる場合
		i=0;
		p=bmp-y*m;
	}
	else{
		i=y;
		p=bmp;
	}
	for(;i<y+n;i++){
		if(i>=VRAM_Y) return; //画面下部に切れる場合
		if(x<0){ //画面左に切れる場合は残る部分のみ描画
			j=0;
			p+=-x;
			vp=VRAM+i*VRAM_X;
		}
		else{
			j=x;
			vp=VRAM+i*VRAM_X+x;
		}
		for(;j<x+m;j++){
			if(j>=VRAM_X){ //画面右に切れる場合
				p+=x+m-j;
				break;
			}
			if(*p!=0){ //カラー番号が0の場合、透明として処理
				*vp=*p;
			}
			p++;
			vp++;
		}
	}
}

void clrbmpmn(int x,int y,unsigned char m,unsigned char n)
// 縦m*横nドットのキャラクター消去
// カラー0で塗りつぶし
{
	int i,j;
	unsigned char *vp;
	if(x<=-m || x>=VRAM_X || y<=-n || y>=VRAM_Y) return; //画面外
	if(y<0){ //画面上部に切れる場合
		i=0;
	}
	else{
		i=y;
	}
	for(;i<y+n;i++){
		if(i>=VRAM_Y) return; //画面下部に切れる場合
		if(x<0){ //画面左に切れる場合は残る部分のみ描画
			j=0;
			vp=VRAM+i*VRAM_X;
		}
		else{
			j=x;
			vp=VRAM+i*VRAM_X+x;
		}
		for(;j<x+m;j++){
			if(j>=VRAM_X){ //画面右に切れる場合
				break;
			}
			*vp++=0;
		}
	}
}

void line(int x1,int y1,int x2,int y2,unsigned int c)
// (x1,y1)-(x2,y2)にカラーcで線分を描画
{
	int sx,sy,dx,dy,i;
	int e;

	if(x2>x1){
		dx=x2-x1;
		sx=1;
	}
	else{
		dx=x1-x2;
		sx=-1;
	}
	if(y2>y1){
		dy=y2-y1;
		sy=1;
	}
	else{
		dy=y1-y2;
		sy=-1;
	}
	if(dx>=dy){
		e=-dx;
		for(i=0;i<=dx;i++){
			pset(x1,y1,c);
			x1+=sx;
			e+=dy*2;
			if(e>=0){
				y1+=sy;
				e-=dx*2;
			}
		}
	}
	else{
		e=-dy;
		for(i=0;i<=dy;i++){
			pset(x1,y1,c);
			y1+=sy;
			e+=dx*2;
			if(e>=0){
				x1+=sx;
				e-=dy*2;
			}
		}
	}
}
void circle(int x0,int y0,unsigned int r,unsigned int c)
// (x0,y0)を中心に、半径r、カラーcの円を描画
{
	int x,y,f;
	x=r;
	y=0;
	f=-2*r+3;
	while(x>=y){
		pset(x0-x,y0-y,c);
		pset(x0-x,y0+y,c);
		pset(x0+x,y0-y,c);
		pset(x0+x,y0+y,c);
		pset(x0-y,y0-x,c);
		pset(x0-y,y0+x,c);
		pset(x0+y,y0-x,c);
		pset(x0+y,y0+x,c);
		if(f>=0){
			x--;
			f-=x*4;
		}
		y++;
		f+=y*4+2;
	}
}

void putfont(int x,int y,unsigned int c,unsigned char n)
//8*8ドットのアルファベットフォント表示
//座標（x,y)、カラー番号c
//n:文字番号
{
	int i,j;
	unsigned char d;
	const unsigned char *p;

	p=FontData+n*8;
	for(i=0;i<8;i++){
		d=*p++;
		for(j=0;j<8;j++){
			if(d&0x80) pset(x+j,y+i,c);
			else pset(x+j,y+i,0);
			d<<=1;
		}
	}
}
void putfont_fixarea(int x,int y,unsigned int c,unsigned char n)
//画面上部固定領域に8*8ドットのアルファベットフォント表示
//座標（x,y)、カラー番号c
//n:文字番号
{
	int i,j;
	unsigned char d;
	const unsigned char *p;

	p=FontData+n*8;
	for(i=0;i<8;i++){
		d=*p++;
		for(j=0;j<8;j++){
			if(d&0x80) pset_fixarea(x+j,y+i,c);
			else pset_fixarea(x+j,y+i,0);
			d<<=1;
		}
	}
}

void printstr(int x,int y,unsigned int c,unsigned char *s){
	//座標(x,y)からカラー番号cで文字列sを表示
	while(*s){
		putfont(x,y,c,*s++);
		x+=8;
	}
}
void printstr_fixarea(int x,int y,unsigned int c,unsigned char *s){
	//画面上部固定領域の座標(x,y)からカラー番号cで文字列sを表示
	while(*s){
		putfont_fixarea(x,y,c,*s++);
		x+=8;
	}
}
void printnum(int x,int y,unsigned char c,unsigned int n){
	//座標(x,y)にカラー番号cで数値nを表示
	unsigned int d,e;
	d=10;
	e=0;
	while(n>=d){
		e++;
		if(e==9) break;
		d*=10;
	}	
	x+=e*8;
	do{
		putfont(x,y,c,'0'+n%10);
		n/=10;
		x-=8;
	}while(n!=0);
}
void printnum_fixarea(int x,int y,unsigned char c,unsigned int n){
	//画面上部固定領域の座標(x,y)にカラー番号cで数値nを表示
	unsigned int d,e;
	d=10;
	e=0;
	while(n>=d){
		e++;
		if(e==9) break;
		d*=10;
	}
	x+=e*8;
	do{
		putfont_fixarea(x,y,c,'0'+n%10);
		n/=10;
		x-=8;
		e--;
	}while(n!=0);
}
void initvscanv(){
//VRAMスキャンベクトル初期化
	vscanv1_x=256;
	vscanv1_y=0;
	vscanv2_x=0;
	vscanv2_y=256;
	vscanstartx=0;
	vscanstarty=0;
}
void pset2(unsigned char x,unsigned char y,unsigned char c)
// (x,y)の位置にカラーcで点を描画（x,yは0-255）
{
	*(VRAM+y*VRAM_X+x)=c;
}
void putfont2(int x,int y,unsigned int c,unsigned char n)
//8*8ドットのアルファベットフォント表示
//座標（x,y)、カラー番号c
//n:文字番号
//画面端で反対側につながっている
//背景色設定なし
{
	int i,j;
	unsigned char d;
	const unsigned char *p;

	p=FontData+n*8;
	for(i=0;i<8;i++){
		d=*p++;
		for(j=0;j<8;j++){
			if(d&0x80) pset((unsigned char)(x+j),(unsigned char)(y+i),c);
			d<<=1;
		}
	}
}
void printstr2(int x,int y,unsigned int c,unsigned char *s){
//座標(x,y)からカラー番号cで文字列sを表示
//画面端で反対側につながっている
//背景色設定なし
	while(*s){
		putfont2(x,y,c,*s++);
		x+=8;
	}
}
void printnum2(int x,int y,unsigned char c,unsigned int n){
//座標(x,y)にカラー番号cで数値nを表示
//画面端で反対側につながっている
//背景色設定なし
	unsigned int d,e;
	d=10;
	e=0;
	while(n>=d){
		e++;
		if(e==9) break;
		d*=10;
	}
	x+=e*8;
	do{
		putfont2(x,y,c,'0'+n%10);
		n/=10;
		x-=8;
	}while(n!=0);
}
void putbmpmn_fixarea(unsigned char x,unsigned char y,unsigned char m,unsigned char n,const unsigned char bmp[]){
//画面上部固定領域にビットマップ表示
//横m*縦nの画像配列bmp[]を座標(x,y)に表示
	unsigned char i;
	unsigned char *p;
	p=TOPVRAM+y*VRAM_X+x;
	for(;n>0;n--){
		for(i=0;i<m;i++){
			*p++=*bmp++;
		}
		p+=VRAM_X-m;
	}
}
void clrbmpmn_fixarea(unsigned char x,unsigned char y,unsigned char m,unsigned char n){
//画面上部固定領域の表示消去
//座標(x,y)からm*nの領域を消去
	unsigned char i;
	unsigned char *p;
	p=TOPVRAM+y*VRAM_X+x;
	for(;n>0;n--){
		for(i=0;i<m;i++){
			*p++=0;
		}
		p+=VRAM_X-m;
	}
}
void putbmpmn2(unsigned char x,unsigned char y,unsigned char m,unsigned char n,unsigned char bmp[]){
// 横m*縦nの画像配列bmp[]をVRAM座標(x,y)に表示
// 画面上下、左右は環状につながっているものとする

	unsigned char i,j,x1;
	for(i=0;i<n;i++){
		x1=x;
		for(j=0;j<m;j++){
			*(VRAM+((unsigned int)y<<8)+x1)=*bmp;
			x1++;
			bmp++;
		}
		y++;
	}
}
void putbmpmn3(unsigned char x,unsigned char y,unsigned char m,unsigned char n,const unsigned char bmp[]){
// 横m*縦nの画像配列bmp[]をVRAM座標(x,y)に表示
// 画面上下、左右は環状につながっているものとする
// bmp[]内データでカラー番号0は透明色として描画しない

	unsigned char i,j,x1;
	for(i=0;i<n;i++){
		x1=x;
		for(j=0;j<m;j++){
			if(*bmp){
				*(VRAM+((unsigned int)y<<8)+x1)=*bmp;
			}
			x1++;
			bmp++;
		}
		y++;
	}
}
