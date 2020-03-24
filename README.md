# TicTacToe
The classic Tic-Tac-Toe game (also called Noughts and Crosses) or Xs and Os is a paper-and-pencil game for two players,
X and O, who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three of their marks in a 
horizontal, vertical, or diagonal row is the winner.

In this code, I've used minimax algorithm to help the computer where to go for the next move and win the puzzle.

### Combinatorics :
When considering only the state of the board, and after taking into account board symmetries (i.e. rotations and reflections),
there are only 138 terminal board positions. A combinatorics study of the game shows that when "X" makes the first move every 
time, the game is won as follows :

>* 91 distinct positions are won by (X)<br>
>* 44 distinct positions are won by (O)<br>
>* 3 distinct positions are drawn (often called a "cat's game")
