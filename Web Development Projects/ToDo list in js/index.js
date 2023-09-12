let EnterBtn = document.getElementById('EnterBtn');
let Textarea = document.getElementById('note');
let saveBtn = document.getElementById('save');
let content;
let title;

function SaveNoteBtn() {
    title = EnterBtn.previousElementSibling.value
    if (localStorage.getItem(title) !== null) {
        Textarea.classList.add('text-danger')
        Textarea.textContent = 'This Task already exists'
    }
    else {
        Textarea.classList.remove('text-danger')
        Textarea.focus()
    }
}
EnterBtn.addEventListener('click', SaveNoteBtn)
EnterBtn.previousElementSibling.addEventListener('keydown', (event) => {
    if (event.key == 'Enter') {
        SaveNoteBtn()
    }
})


function SaveNote() {
    content = Textarea.value
    localStorage.setItem(title, content)
    Textarea.value = ''
    EnterBtn.previousElementSibling.value = ''
    alert('Task Saved')
}
Textarea.addEventListener('keydown', (event) => {
    if (event.key == 'Enter') {
        SaveNote()
    }
})
saveBtn.addEventListener('click', SaveNote)


let Readarea = document.getElementById('Readarea');
let ReadBtn = document.getElementById('ReadBtn');
function ReadNote() {
    title = ReadBtn.previousElementSibling.value
    if (localStorage.getItem(title) === null) {
        Readarea.classList.add('text-danger')
        Readarea.textContent = 'Sorry,No Task with this Task title is found.Please Enter a correct title'
    }
    else {
        Readarea.classList.remove('text-danger')
        Readarea.textContent = localStorage.getItem(title)
    }
}
ReadBtn.addEventListener('click', ReadNote)
ReadBtn.previousElementSibling.addEventListener('keydown', (e) => {
    if (e.key == 'Enter') {
        ReadNote();
    }
})

let ShowAll = document.getElementById('ShowAll')
let ModalBody = document.getElementById('modalMain')
ShowAll.addEventListener('click', () => {
    ModalBody.innerHTML = ''
    for (let i = 0; i < localStorage.length; i++) {
        let NTitle = localStorage.key(i);
        let value = localStorage[NTitle]
        ModalBody.innerHTML += `<h3 class='fst-italic text-dark'><u>Task  ${i + 1}.${NTitle}</u></h3>
		<p class='text-primary fs-5'>${value}</p>`

    }
})



let DelBtn = document.getElementById('DelBtn')
let Delarea = document.getElementById('Delarea')
function DelNote() {
    title = DelBtn.previousElementSibling.value
    if (localStorage.getItem(title) === null) {
        Delarea.classList.remove('text-success')
        Delarea.classList.add('text-danger')
        Delarea.textContent = 'Sorry,No Task with this Task title is found.Please Enter a correct title'
    }
    else {
        let con = confirm("Do you Really want to delete this Task!")
        if (con) {
            Delarea.classList.remove('text-danger')
            Delarea.classList.add('text-success')
            localStorage.removeItem(title)
            Delarea.textContent = `Delete Status: Your Task titled "${title}" is successfully Deleted`
        }
        else {
            DelBtn.previousElementSibling.textContent = ''
            Delarea.textContent = ''
        }
    }
}
DelBtn.addEventListener('click', DelNote)
DelBtn.previousElementSibling.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') {
        DelNote();
    }
})


let DelAll = document.getElementById('DelAll');
DelAll.addEventListener('click', () => {
    let con = confirm("Warning! this will delete all your Tasks.Still want to continue?")
    if (con) {
        localStorage.clear()
        alert('all your Tasks are deleted')
    }
})



let UpdtEntBtn = document.getElementById('UpdtEntBtn')
let UpdtBtn = document.getElementById('UpdtBtn')
let Updtarea = document.getElementById('Updtarea')
let data;

function UpdtNotesBtn() {
    title = UpdtEntBtn.previousElementSibling.value
    if (localStorage.getItem(title) === null) {
        Updtarea.classList.add('text-danger')
        Updtarea.textContent = 'Sorry,No Task with this Task title is found.Please Enter a correct title'
    }
    else {
        Updtarea.classList.remove('text-danger')
        data = localStorage.getItem(title)
        Updtarea.value = data
        Updtarea.focus()
    }
}

function UpdtNote() {
    content = Updtarea.value
    localStorage.setItem(title, content)
    Updtarea.value = ''
    UpdtEntBtn.previousElementSibling.value = ''
    alert('Task Updated')
}
UpdtEntBtn.addEventListener('click', UpdtNotesBtn)
UpdtEntBtn.previousElementSibling.addEventListener('keydown', (e) => {
    if (e.key == 'Enter') {
        UpdtNotesBtn();
    }
})

UpdtBtn.addEventListener('click', UpdtNote)
UpdtBtn.previousElementSibling.addEventListener('keydown', (e) => {
    if (e.key == 'Enter') {
        UpdtNote();
    }
})
