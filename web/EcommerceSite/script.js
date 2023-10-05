const a = document.getElementById('bar');
const b= document.getElementById('navbar');
const c= document.getElementById('close');
if(a){
    a.addEventListener("click", function(){
        b.classList.add("active");
    });
}

if(c){
    c.addEventListener("click", function(){
        b.classList.remove("active");
    })
}