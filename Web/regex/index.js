/* jshint esversion : 6 */

function match() {
    let mode = evil('/'+document.getElementById("mode")+'/g');
    let text = document.getElementById("text");
    let result = mode.exec(text);
    let count = 0;
    let color = Array( 'rgb(255,0,255)' , 'rgb(255,255,0)' , 'rgb(0,255,255)' , 'rgb(168, 38, 207)', 'rgb(50, 180, 255)', 'rgb(207, 204, 38)' );
    let txt = text.substring(0,result.index-count);
    text = text.substring(result.index-count, text.length);
    count += result.index;
    while( result != null ) {
        let len = result.length - 2;
        for(i=0; i<len; i++ ) {
            tmp = result[0];
            
        }
    }

}

let mod = evil('/'+'([\\d]+d)a([\\d]+)'+'/g');
let text = "46da63daasdsd44da54";
result = mod.exec(text);
console.log(result);
result = mod.exec(text);
console.log(result.index);

function evil(fn) {
    var Fn = Function;
    return new Fn('return ' + fn)();
}