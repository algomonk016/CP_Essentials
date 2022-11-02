/*

Tower of Hanoi
  given 3 rods, [A, B, C]
  move all discs on rod A to C, with following conditions
    - final state of rod C should be same as initial state of rod A
    - can place disc on rod C, if top of rod C has bigger disc on top

  Approach:
    move n-1 discs to B, then last disc to rod C
    n-1 discs to A, then last disc to rod C
*/

void TowerOfHanoi(int n, char from, char helper, char to){
  if(n == 0) return;

  TowerOfHanoi(n-1, from, to, helper);

  cout<<from<<" -> "<<to<<'\n';

  // nth rod to TO
  TowerOfHanoi(n-1, helper, from, to);
}