const secondHand = document.querySelector(".second-hand");
const minsHand = document.querySelector(".min-hand");
const hourHand = document.querySelector(".hour-hand");
const dates = document.querySelector(".date");
const times = document.querySelector(".times");

const getPM = (t) => {
    t[0] > 12 ? t[0] - 12 + ':' + t[1] + ' PM' : t[0] + ':' + t[1] + ' PM';
}
const getAM = (t) => {
    t[0] = t[0] == 0 ? 12 : t[0];
    return t[0] + ':' + t[1] + ' AM';
    // return t[0] == 0 ?  ?
}


function setDate() {
    const now = new Date();

    const seconds = now.getSeconds();
    const secondsDegrees = (seconds / 60) * 360 + 90;
    secondHand.style.transform = `rotate(${secondsDegrees}deg)`;

    const mins = now.getMinutes();
    const minsDegrees = (mins / 60) * 360 + (seconds / 60) * 6 + 90;
    minsHand.style.transform = `rotate(${minsDegrees}deg)`;

    const hour = now.getHours();
    const hourDegrees = (hour / 12) * 360 + (mins / 60) * 30 + 90;
    hourHand.style.transform = `rotate(${hourDegrees}deg)`;

    dates.innerText = now.getDate() + ':' + now.getMonth();

    let t = hour + ":" + mins;
    t = t.split(':');
    times.innerText = t[0] >= 12 ? getPM(t) : getAM(t);
}

setInterval(setDate, 1000);

setDate();