/* jshint esversion : 6 */
$(document).ready(function(){
    $("body").keydown( function(event){
        $("#p").html(event.which);
        console.log(event.data);
    } );
});