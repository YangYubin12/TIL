 function checking(){
    if(frm.resvno.value.length === 0){
        alert("예약번호가 입력되지 않았습니다.")
        frm.resvno.focus();
    }
    else if(frm.empno.value.length === 0){
        alert("사원번호가 입력되지 않았습니다.")
        frm.resvno.focus();
    }
    else if(frm.resvdate.value.length === 0){
        alert("근무일자가 입력되지 않았습니다.")
        frm.resvdate.focus();
    }
    else if(frm.seatno.value.length === 0){
        alert("좌석번호가 입력되지 않았습니다.")
        frm.seatno.focus();
    }
    else{
	alert("좌석 예약정보가 등록되었습니다.")
	frm.submit();
	}
}
 function listcheck(){
    if(frm2.empno.value.length === 0){
        alert("사원번호가 입력되지 않았습니다.")
        frm2.empno.focus();
    }
    else{
	alert("좌석예약을 조회합니다.")
	frm2.submit();
	//window.location = "list2.jsp"
	}
}
function reseting(){
    alert("정보를 지우고 처음부터 다시 입력합니다!")
    document.frm.reset()
}
