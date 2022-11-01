function addCheck() {
    if(frm.id.value.length == 0) {
        alert("교과목 코드가 입력되지 않았습니다.");
        frm.id.focus();
        return false;
    }
    else if(frm.name.value.length == 0) {
        alert("과목명이 입력되지 않았습니다.");
        frm.name.focus();
        return false;
    }
    else if(frm.credit.value.length == 0) {
        alert("학점이 입력되지 않았습니다.");
        frm.credit.focus();
        return false;
    }
    else if(frm.lecturer.value == 0) {
        alert("담당강사가 입력되지 않았습니다.");
        frm.lecturer.focus();
        return false;
    }
    else if(frm.week[0].checked == false && frm.week[1].checked == false &&
		frm.week[2].checked == false && frm.week[3].checked == false &&
		frm.week[4].checked == false){
			alert("요일이 입력되지 않았습니다.");
			frm.week.focus();
			return false;
	}
    else if(frm.start_hour.value.length == 0) {
        alert("시작 시간이 일력되지 않았습니다.");
        frm.start_hour.focus();
        return false;
    }
    else if(frm.end_hour.value.length == 0) {
        alert("종료 시간이 입력되지 않았습니다.");
        frm.end_hour.focus();
        return false;
    }
    else {
		alert("교과목 등록이 완료되었습니다!");
		document.frm.submit();
		return true;
	}
}
	function modify(){
		alert("교과목 수정이 완료되었습니다!");
		document.frm.submit();
		return true;
	}
	function search(){
		window.location='list.jsp';
	}	
	function res(){
		alert("교과목 수정이 취소되었습니다.");
		document.frm.reset();
	}	
	