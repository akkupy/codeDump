console.log("This code is executed in the browser");

const stone = document.querySelector('.stone')
const paper = document.querySelector('.paper')
const scissors = document.querySelector('.scissors')

stone.addEventListener('click',()=>{
    if(paper.classList.contains('paper')){
       
        paper.classList.add('active');

        stone.classList.remove('active');
        scissors.classList.remove('active');
    }
});

paper.addEventListener('click',()=>{
    if(scissors.classList.contains('scissors')){
       
        scissors.classList.add('active');

        paper.classList.remove('active');
        stone.classList.remove('active');
    }
});

scissors.addEventListener('click',()=>{
    if(stone.classList.contains('stone')){
       
        stone.classList.add('active');
        
        paper.classList.remove('active');
        scissors.classList.remove('active');

    }
});


