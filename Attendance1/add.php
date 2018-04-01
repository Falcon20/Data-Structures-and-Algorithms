<?php
include("header.php");
include("db.php");
if(isset($_POST['submit']))
{
	if(mysqli_query($con,"insert into attendance(student_name,roll_no)values('$_POST[name]','$_POST[roll]') "))
		?>
	<script>
		alert("Data inserted Successfully");
	</script>
	<?php
	
}

?>
<div class="container">
<div class="panel panel-default">
	<div class="panel-heading">
	<h2><a class="btn btn-success" href="add.php">Add Student</a>
	<a class="btn btn-info pull-right" href="index.php">Back</a>
	</h2>
	</div>
<div class="panel-body">
<form action="add.php" method="post">
	<div class="form-group">
		<lable for="name"> Student Name</lable>
		<input type="text" name="name" id="name" class="form-control" required>
	</div >
	<div class="form-group">
		<lable for="roll">Roll no</lable>
		<input type="text" name="roll" id="roll" class="form-control" required>
	</div >
	<div class="form-group">
		
		<input type="submit" name="submit" value="Submit" class="btn btn-primary" required>
	</div >
</form>
</div>
