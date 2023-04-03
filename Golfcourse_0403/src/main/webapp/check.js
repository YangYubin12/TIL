 function checking(){
    if(frm.date.value.length === 0){
        alert("수강일이 입력되지 않았습니다.")
        frm.date.focus()
        return false
    }
    else if(frm.memberName.value === 0){
        alert("회원명이 입력되지 않았습니다.")
        frm.memberName.focus()
        return false
    }
    else if(frm.area.value === 0){
        alert("회원명이 입력되지 않았습니다.")
        frm.memberName.focus()
        return false
    }
    else if(frm.className.value === 0){
        alert("회원명이 입력되지 않았습니다.")
        frm.memberName.focus()
        return false
    }
    alert("수강신청이 정상적으로 완료되었습니다!")
    document.frm.submit()
    return true
}

function reseting(){
    alert("정보를 지우고 부터 다시 입력합니다!")
    document.frm.reset()
}
function getNumber(number){
    memberNumber = number
    frm.number.value = number
}
function getPrice(price) {
    if(membernumber >= 20000) frm.price.value = price/2;
    else frm.price.value = price
}