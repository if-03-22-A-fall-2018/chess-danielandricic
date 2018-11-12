/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess_printer.c
 * Author:			Daniel Andricic
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Functions for printing a chess board.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#include "chess_printer.h"
#include "chess.h"

void print_chess_board(ChessBoard chess_board)
{
	struct ChessSquare square;
	int i;
	int j;
	ChessPieceSymbol piece_symbol;

	printf("   a   b   c   d   e   f   g   h\n");
	printf(" +---+---+---+---+---+---+---+---+\n");
	for (i = 0; i < 8; i++) {
		printf("%d", 8 - i);
		for (j = 0; j < 8; j++) {
			square = chess_board[i][j];
			if (square.is_occupied) {
				if (!get_piece_symbol(square.piece, piece_symbol)) {
					printf("Buffer for printing too small\n");
				}
			}
			else {
				strcpy(piece_symbol, " ");
			}
			printf("| %s ", piece_symbol);
		}
		printf("|\n");
		printf(" +---+---+---+---+---+---+---+---+\n");
	}
}

bool get_piece_symbol(struct ChessPiece piece, ChessPieceSymbol piece_symbol)
{
	char color_pre[7] = "";
	char color_post[5] = "";
	bool piece_found = true;

	strcpy(piece_symbol, "");

	if (piece.color == White) {
		strcpy(color_pre, "\033[31m");
		strcpy(color_post, "\033[m");
	}

	strcat(piece_symbol, color_pre);

	switch (piece.type) {
	case Pawn:
		strcat(piece_symbol, "P");
		break;

	case Rook:
		strcat(piece_symbol, "R");
		break;

	case Knight:
		strcat(piece_symbol, "N");
		break;

	case Bishop:
		strcat(piece_symbol, "B");
		break;

	case Queen:
		strcat(piece_symbol, "Q");
		break;

	case King:
		strcat(piece_symbol, "K");
		break;

	default:
		piece_found = false;
		break;
	}
	strcat(piece_symbol, color_post);

	return piece_found;
}
