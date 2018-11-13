/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			Daniel Andricic
 * Due Date:		November 03, 2018
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include "chess.h"
 #include <stdlib.h>

bool add_piece(ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece)
{
  if (chess_board[rank - 1][file - 'a'].is_occupied == false && is_square_ok(file, rank) == true)
  {
       chess_board[rank - 1][file - 'a'].is_occupied = true;
       chess_board[rank - 1][file - 'a'].piece = piece;
       return true;
  }
  return false;
}
struct ChessPiece get_piece(ChessBoard chess_board, File file, Rank rank)
{
  if(!is_square_ok(file, rank)){
    chess_board[rank - 1][file - 'a'].piece.type = NoPiece;
    return chess_board[rank - 1][file -'a'].piece;
  }
  return chess_board[rank - 1][file - 'a'].piece;
}
struct ChessSquare* get_square(ChessBoard chess_board, File file, Rank rank)
{
  int column = rank;
  char raw = file;
  if (is_square_ok(file, rank)){
      return &chess_board[column - 1][raw -'a'];
  }
  return 0;
}

bool is_square_ok(File file, Rank rank)
{
  return file >='a' && file <= 'h' && rank >= 1 && rank <= 8;
}

void init_chess_board(ChessBoard chess_board)
{
  for(int i=0; i<8;i++)
  {
      for(int j=0;j<8;j++)
      {
        chess_board[i][j].is_occupied=false;
        chess_board[i][j].piece.type=NoPiece;
      }
    }
}
bool is_move_from_base_line(enum PieceColor color, Rank rank)
{
  if(color == White)
  {
    if(rank == 1){
      return false;
    }
    return true;
  }
  else
  {
    if(rank == 8){
      return false;
    }
    return true;
  }
}
bool is_piece(struct ChessPiece pc, enum PieceColor color, enum PieceType type)
{
  return pc.color == color && pc.type == type;
}
bool is_square_occupied(ChessBoard chess_board, File file, Rank rank)
{
  return chess_board[rank - 1][file - 'a'].is_occupied;
}

int nf(File file)
{
  return file;
}
int nr(Rank rank)
{
  return rank;
}
bool remove_piece(ChessBoard chess_board, File file, Rank rank)
{
  if (is_square_occupied(chess_board,file,rank) == true)
  {
    chess_board[rank - 1][file - 'a'] = {0};
    return true;
  }
  return false;
}
void setup_chess_board(ChessBoard chess_board)
{
   init_chess_board(chess_board);
   for (char x = 'a'; x <= 'h'; x++)
   {
     add_piece(chess_board, x, 2, {White, Pawn});
     add_piece(chess_board, x, 7, {Black, Pawn});
   }
   add_piece(chess_board, 'a', 1, {White, Rook});
   add_piece(chess_board, 'h', 1, {White, Rook});
   add_piece(chess_board, 'b', 1, {White, Knight});
   add_piece(chess_board, 'g', 1, {White, Knight});
   add_piece(chess_board, 'c', 1, {White, Bishop});
   add_piece(chess_board, 'f', 1, {White, Bishop});
	 add_piece(chess_board, 'd', 1, {White, Queen});
   add_piece(chess_board, 'e', 1, {White, King});
   add_piece(chess_board, 'a', 8, {Black, Rook});
   add_piece(chess_board, 'h', 8, {Black, Rook});
   add_piece(chess_board, 'b', 8, {Black, Knight});
   add_piece(chess_board, 'g', 8, {Black, Knight});
   add_piece(chess_board, 'c', 8, {Black, Bishop});
   add_piece(chess_board, 'f', 8, {Black, Bishop});
   add_piece(chess_board, 'd', 8, {Black, Queen});
   add_piece(chess_board, 'e', 8, {Black, King});
}
bool squares_share_diagonal(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  return abs(s2_f-s1_f)==abs(s2_r-s1_r)&&is_square_ok(s1_f,s1_r)&&is_square_ok(s2_f, s2_r);

}
bool squares_share_file(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if(is_square_ok(s1_f, s1_r) && is_square_ok(s2_f, s2_r))
  {
      return s1_f == s2_f;
  }

}
bool squares_share_kings_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if (is_square_ok(s1_f,s1_r)&& is_square_ok(s2_f,s2_r))
  {
    return squares_share_diagonal(s1_f, s1_r, s2_f, s2_r) || s1_f == s2_f || s1_r == s2_r ;
  }
  return false;
}
bool squares_share_knights_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if (is_square_ok(s1_f,s1_r) && is_square_ok(s2_f,s2_r))
  {
      return squares_share_diagonal(s1_f, s1_r, s2_f, s2_r);
  }
  return false;
}
bool squares_share_pawns_move(enum PieceColor color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if(is_square_ok(s1_f, s1_r)&& is_square_ok(s2_f, s2_r))
  {
    if(s1_r == s2_r - 1 || s2_r == s1_r -1 || s2_r == s1_r)
    {
      return true;
    }
  }
  else
  {
    return false;
  }
}
bool squares_share_queens_move(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if (is_square_ok(s1_f,s1_r) && is_square_ok(s2_f,s2_r))
  {
    return (squares_share_diagonal(s1_f, s1_r, s2_f, s2_r) == true || s1_f == s2_f || s1_r == s2_r );
  }
  return false;
}
bool squares_share_rank(File s1_f, Rank s1_r, File s2_f, Rank s2_r)
{
  if(is_square_ok(s1_f, s1_r) && is_square_ok(s2_f, s2_r)){
    return s1_r == s2_r;
  }
  return false;
}
