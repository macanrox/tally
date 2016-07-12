$(document).ready(function(){
	var count = 0;

	$(document).on("click", ".tdAdd", function(){
		count = $('#tableCount tr').length-1;
		var row = $("<tr>");
		var col = "";

		col += '<td><input type="button" value="Add Row" class="tdAdd"/></td>';
		col += '<td><input type="text" name="name' + count + '"/></td>';
		col += '<td><input type="button" value="Delete" class="tdDel"/></td>';
		row.append(col);
		$("table.order-list").append(row);
		count++;
		console.log(count);
	});

	$("table.order-list").on("click", ".tdDel", function(event){
		count -= 1;
		if(count <= 0){
			window.alert("There needs to be at least one entry! Please add more rows.");
		}
		else {
			$(this).closest("tr").remove();
		}
		console.log(count);
	});

});

function submitForm(formID){
		console.log(formID);
		var form = document.getElementById(formID);
		var formElem = document.getElementsByClassName(formID);
		var i;
		
		for(i=0; i < formElem.length; i++){
			form.appendChild(formElem[i]);
		}
		console.log(formElem);
		//form.submit();
};