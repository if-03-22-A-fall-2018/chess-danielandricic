/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess_printer.h
 * Author:			Daniel Andricic
 * Due Date:		November 12, 2018
 * ----------------------------------------------------------
 * Description:
 * Functions for printing a chess board.
 * ----------------------------------------------------------
 */

#ifndef ___CHESS_PRINTER_H
#define ___CHESS_PRINTER_H

#include "chess.h"

/** Constant defining the length of the string holding the symbol
*** of a chess piece. This string also holds the color information
*** and, therefore, has to get this length. */
#define PIECE_SYMBOL_STRING_LEN 14

/** The chess piece symbol holds the printable form of a chess piece. */
typedef char ChessPieceSymbol[PIECE_SYMBOL_STRING_LEN];

/** print_chess_board prints a chess board into the terminal window.
*** @param chess_board The chess board to be printed.
*/
void print_chess_board(ChessBoard chess_board);

/** Provides a printable symbol for a specific chess piece.
*** @param piece The chess piece which symbol to be returned.
*** @param piece_symbol The symbol of the chess piece in printable form
*** @return True if the requested symbol was found, i.e, the given piece
*** has a valid color and type, False otherwise.
*** @see PieceType, PieceColor, ChessPiece
*/
bool get_piece_symbol(struct ChessPiece piece, ChessPieceSymbol piece_symbol);

#endif
