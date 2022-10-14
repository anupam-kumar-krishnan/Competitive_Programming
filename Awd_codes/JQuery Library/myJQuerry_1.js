$(document).ready(function(){
    console.log("Now jquery is in a seperate file")


    // $('p').dblclick(function(){
    //     console.log('you double clicked on p', this)
    // });

    
    // $('p').mouseenter(function(){
    //     console.log('you entered:', this)
    // });

    
    // $('p').mouseleave(function(){
    //     console.log('you leave from:', this)
    // });


    
    // $('p').hover(function(){
    //     console.log('you hovered on:', this)
    // });


    // $('p').hover(function(){
    //     console.log('you hovered on:', this)
    // },
    // function()
    // {
    //     console.log("Exiting...!")
    // });


    // $('p').keypress(function(){
    //     console.log('you double pressed on p', this)
    // });


    $(document).ready(function(){
        var i = 0;
        $('input[type="text"]').keypress(function(){
            $("span").text(i += 1);
            if (i>=11){
                window.alert("u have enter more than 10 characters")
            }
            $("input").focus(function(){
                $(this).next("abc").show().fadeOut("slow");
            }); });
            $("p").show().fadeOut();
        });

        
     //for untitled 1


    // $('#learning').hide(10000)


    // $('p').keyup(function(){
    //     console.log('you double clicked on p', this)
    // });

    
    // $('p').dblclick(function(){
    //     console.log('you double clicked on p', this)
    // });


    // $('#learning').hide(10000,function(){
    //     console.log("content hiding completed")
    // })
    // $('#learning').show(30000,function(){
    //     console.log("content comes back")
    // })

    
});
