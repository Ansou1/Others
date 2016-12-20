function saveData(filename, obj, success, failed){
    // window.sessionStorage.getItem("accounts", JSON.stringify(data));
    writeData(filename, obj, success, failed);
}

function getData(filename, onSuccess, onfailure){
	window.resolveLocalFileSystemURL(cordova.file.dataDirectory + filename,
		function (fileEntry){
	  		fileEntry.file(function(file) {
	        	var reader = new FileReader();

	        	reader.onloadend = function(e) {
	        		console.log("file read with success!");
	        		console.log("Successful file read: " + this.result);
	        		onSuccess(this.result);
	        	}
	        	reader.readAsText(file);
    		});
		},
		onfailure
	);
}

function fail(e){
	console.log("FileSystem Error");
    console.dir(e);
}

function fileDoesNotExist(){
    console.log("file does not exist");
}

function getFSFail(evt) {
    console.log(evt.target.error.code);
}

function writeData(filename, data, success, failure){
	window.resolveLocalFileSystemURL(cordova.file.dataDirectory, function(dir) {
        dir.getFile(filename, {create:true}, function(file) {
            logOb = file;
            writeFile(JSON.stringify(data), success, failure);
        }, fileDoesNotExist);
    }, getFSFail);
}

function truncateFile(writer, data, success, failure){
	writer.onwriteend = function(evt){
		writer.seek(0);
		writer.onwriteend = function(evt){
            console.log("data has been wrote!");
            success();
        }
		writer.write(data);
	}
	writer.truncate(0);
}

function writeFile(str, success, failure) {
    if(!logOb) return;
    logOb.createWriter(function(fileWriter) {
    	truncateFile(fileWriter, str, success);
    }, fileDoesNotExist);
}
