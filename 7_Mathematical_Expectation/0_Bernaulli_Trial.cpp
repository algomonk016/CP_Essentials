/*
  Bernaulli's Trial
    jb 2 hi outcomes ho, true/false , success/failure
  
  Theorem 1
    If the probability of success of a bernaulli trial is P, then the expected number of trials to get a success is 1/P

    P(H) -> 1/2
    N -> 2

  Theorem 2
    If probability of getting succes in Bernaulli Trial is P, then expected number of success in N trials is NP
*/

/*
  Choose number
    N students are asked to choose a number from 1 to 100. What is the expeted number of students that would choose a single digit number?

    Single student, P (Single Digit) -> 9/100
    using Th 2: for N students, P(Single Digit) -> 9N/100
*/ 

/*
  Interview Candidates
    Candidates are appearing for interview one after other.
    Probability of each candidate getting selected is 0.16.
    What is the expected number of candidates that you will need to interview to make sure that you select somebody?

    P = 0.16
    N = 1/0.16 (Th 1)
    N = 6.25 --> 7

    solving
      N*(0.16) >= 1;
      N >= 1/0.16
      N >= 6.25
      N = 7
*/ 