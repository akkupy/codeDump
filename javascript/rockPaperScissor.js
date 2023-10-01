const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function computerPlay() {
  const choices = ['rock', 'paper', 'scissors'];
  const randomIndex = Math.floor(Math.random() * choices.length);
  return choices[randomIndex];
}

function playRound(playerSelection, computerSelection) {
  if (playerSelection === computerSelection) {
    return "It's a tie!";
  } else if (
    (playerSelection === 'rock' && computerSelection === 'scissors') ||
    (playerSelection === 'paper' && computerSelection === 'rock') ||
    (playerSelection === 'scissors' && computerSelection === 'paper')
  ) {
    return 'You win!';
  } else {
    return 'Computer wins!';
  }
}

function startGame() {
  rl.question('Choose your move (rock, paper, or scissors): ', (playerSelection) => {
    const computerSelection = computerPlay();
    const result = playRound(playerSelection.toLowerCase(), computerSelection);
    console.log(`You chose ${playerSelection}. Computer chose ${computerSelection}. ${result}`);

    rl.question('Do you want to play again? (yes/no): ', (answer) => {
      if (answer.toLowerCase() === 'yes') {
        startGame();
      } else {
        console.log('Thanks for playing!');
        rl.close();
      }
    });
  });
}

console.log('Welcome to Rock, Paper, Scissors!');
startGame();
