const star = "* ";
//where length is no of stars in longest streak
const length = 6;
for(let i = 1; i <= (length*2)-1; i++){
   const k = i <= length ? i : (length*2)-i;
   console.log(star.repeat(k));
}
