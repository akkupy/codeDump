let score = JSON.parse(localStorage.getItem('score')) || {
    wins: 0,
    losses: 0,
    ties: 0
};

updateScoreElement();

/* 
if (!score) {
score = {
    wins: 0,
    losses: 0,
    ties: 0
}
}
*/

function playGame(playMove) {

const computerMove = pickComputerMove();
let result;

if (playMove === 'Rock') {
    if (computerMove === 'Rock') {
        result = 'Tie';
    }
    else if (computerMove === 'Paper') {
        result = 'You Lose';
    }
    else if (computerMove === 'Scissors') {
        result = 'You Win';
    }
}

else if (playMove === 'Paper') {
    if (computerMove === 'Rock') {
        result = 'You Win';
    }
    else if (computerMove === 'Paper') {
        result = 'Tie';
    }
    else if (computerMove === 'Scissors') {
        result = 'You Lose';
    }
}

else if (playMove === 'Scissors') {

    if (computerMove === 'Rock') {
        result = 'You Lose';
    }
    else if (computerMove === 'Paper') {
        result = 'You Win';
    }
    else if (computerMove === 'Scissors') {
        result = 'Tie';
    }
}

if (result === 'You Win') {
    score.wins++;
}
else if (result === 'You Lose') {
    score.losses++;
}
else if (result === 'Tie') {
    score.ties++;
}

localStorage.setItem('score', JSON.stringify(score));

updateScoreElement();

document.querySelector('.js-result').innerHTML = result;

document.querySelector('.js-moves').innerHTML = `You 
<img src="images/${playMove}-emoji.png" class="move-icon" alt="">
<img src="images/${computerMove}-emoji.png" class="move-icon" alt="">
Computer`;

}

function updateScoreElement() {
document.querySelector('.js-score')
    .innerHTML = `Wins: ${score.wins}, Losses: ${score.losses}, Ties: ${score.ties}`;
}

function pickComputerMove() {

const randomNumber = Math.random();

if (randomNumber >= 0 && randomNumber < 1 / 3) {
    computerMove = 'Rock';
}
else if (randomNumber >= 1 / 3 && randomNumber < 2 / 3) {
    computerMove = 'Paper';
}
else if (randomNumber >= 2 / 3 && randomNumber < 1) {
    computerMove = 'Scissors';
}
return computerMove;
}