let g_btn = document.getElementById("btn1");

g_btn.addEventListener('click', buttonClickHandler)


function buttonClickHandler(){
    console.log("You have clicked the Get Button");
    
    const xhr = new XMLHttpRequest();

    xhr.open('GET', "ajaxServer.txt", true)

    xhr.onprogress = function(){
        console.log("on progress......!")
    }

    xhr.onload = function(){
        if (this.status === 200){
            console.log(this.responseText);
        }
        else
        {
            console.error("Some error occured");
        }
    }

    xhr.send();

}