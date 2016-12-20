function loadData(filename, success){
    getData(filename,
    function(result){
        success(JSON.parse(result));
    },
    function(err){
        console.log(filename + ' No file found.');
        success(null);
    });
}

function loadAppData(data, ondataloaded){
  var name = data.pop();
	window[name].load(function(){
		if (data.length > 0){
			loadAppData(data, ondataloaded);
		} else {
			ondataloaded();
		}
	});
}
