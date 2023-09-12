let input=document.getElementById('inputbox');
let buttons=document.querySelectorAll('button');

let string ="";

let x =function(e){
    if (e.target.innerHTML=='=')
    {
        string=eval(string);
        
        input.value=string;
    }
    else if(e.target.innerHTML=='AC') {
          string='';
          input.value=string;
    }
    else{
        string+=e.target.innerHTML;
        input.value=string;
    }
}

let arr=Array.from(buttons);
arr.forEach(button =>{
           button.addEventListener('click',x)})
           