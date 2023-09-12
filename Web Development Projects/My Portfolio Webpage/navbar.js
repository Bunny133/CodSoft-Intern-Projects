// active toggle
let AllNavlinkA = document.querySelectorAll(".nav-links li a");

//active add
AllNavlinkA.forEach((item) => {
  item.addEventListener("click", () => {
    removeActive();
    item.classList.add("active");
  });
});

//active remove
const removeActive = () =>
  AllNavlinkA.forEach((item) => {
    item.classList.remove("active");
  });
document.addEventListener("DOMContentLoaded", function () {
  // Toggle the mobile menu
  var menuButton = document.querySelector(".nav-btn .fa-bars");
  var menu = document.querySelector(".nav-container .nav-links");
  var menuIcon = document.querySelector(".nav-links i");

  menuButton.addEventListener("click", function () {
    menu.classList.toggle("active");
    menuIcon.classList.toggle("active");
  });

  // Close the mobile menu when a menu item is clicked
  var menuLinks = document.querySelectorAll(".nav-container .nav-links a");
  menuLinks.forEach(function (link) {
    link.addEventListener("click", function () {
      menu.classList.remove("active");
      menuIcon.classList.remove("active");
    });
  });
});

// //direct to my social media accounts
// let fb = document.querySelector('.fab.fa-facebook');

// fb.addEventListener('click', () => {

//   window.location.href = 'https://www.facebook.com/mtayyab.warriach?mibextid=2JQ9oc';
// });

const dynamicTextElements = document.querySelectorAll(".typing");
const words = ["Web Developer", "Programmer"];

dynamicTextElements.forEach((dynamicText) => {
  let wordIndex = 0;
  let charIndex = 0;
  let isDeleting = false;

  const typeEffect = () => {
    const currentWord = words[wordIndex];
    const currentChar = currentWord.substring(0, charIndex);
    dynamicText.textContent = currentChar;
    dynamicText.classList.add("stop-blinking");

    if (!isDeleting && charIndex < currentWord.length) {
      charIndex++;
      setTimeout(typeEffect, 100);
    } else if (isDeleting && charIndex > 0) {
      charIndex--;
      setTimeout(typeEffect, 30);
    } else {
      isDeleting = !isDeleting;
      dynamicText.classList.remove("stop-blinking");
      wordIndex = !isDeleting ? (wordIndex + 1) % words.length : wordIndex;
      setTimeout(typeEffect, 1000);
    }
  };

  typeEffect();
});

function darkMode() {
  var icon = document.querySelector(".nav-container .nav-links i");
  var newIcon = document.querySelector(".nav-btn .fa-regular");
  var body = document.body;
  var computedIconStyle = getComputedStyle(icon).display;
  body.classList.toggle("dark-mode");

  if (body.classList.contains("dark-mode")) {
    localStorage.setItem("darkmode", "enabled");
    if (computedIconStyle !== "none") {
      icon.classList.remove("fa-sun");
      icon.classList.add("fa-moon");
    } else {
      newIcon.classList.remove("fa-sun");
      newIcon.classList.add("fa-moon");
    }
  } else {
    localStorage.setItem("darkmode", "disabled");
    if (computedIconStyle !== "none") {
      icon.classList.add("fa-sun");
      icon.classList.remove("fa-moon");
    } else {
      newIcon.classList.add("fa-sun");
      newIcon.classList.remove("fa-moon");
    }
  }
}
var changeColor = document.getElementById("icon");
changeColor.addEventListener("click", darkMode);

const savedDarkMode = localStorage.getItem("darkmode");
if (savedDarkMode === "enabled") {
  document.body.classList.add("dark-mode");
}
