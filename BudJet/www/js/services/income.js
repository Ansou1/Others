app.factory("incomes", ["accounts", function(accounts){
	var data = [];
	var sdo = {
		get : function(id){
		    for(var i =0;i<data.length;i++){
		      if (data[i].id == id){
		      return data[i];
		      }
		    }
		    return null;
	  	},

		getIncomes : function(){
			return data;
		},

	  	load : function(success){
		    loadData(config.files.incomes, function(result){
		      if (result == null) result = [];
		      for (var i =0;i<result.length;i++){
						result[i].date = new Date(result[i].date);
					}
		      data = result;
		      console.log("incomes", data);
		      success();
		    });
	  	},

	  	add: function(income, success, failure){
	  		if (income.id == undefined || income.id == null) income.id = uniqid();
		    var account = accounts.get(income.account);
		    if (account)
		    	account.money = account.money + income.money;
		    data.push(income);
		    saveData(config.files.incomes, data, function(){
		      saveData(config.files.accounts, accounts.getAccounts(), function(){
		        success(income);
		      }, failure);
		    }, failure);
	  	},

	  	update: function(income, success, failure){
			var a = this.get(income.id);
			if (a === null) return;
			if (income.name != null) a.name = income.name;
			if (income.money != null) a.money = income.money;
			if (income.account != undefined) a.account = income.account;
			if (income.date != null) a.date = new Date(income.date);

			saveData(config.files.incomes, data, function(){
			    success(income);
		  	}, failure);
	  	},

	  	delete: function(income, success, failure){
	  		for(var i =0;i<data.length;i++){
		      if (data[i].id == income.id){
		        	data.splice(i, 1);
		        	saveData(config.files.incomes, data, function(){
		            	success();
		          	}, failure);
	          		return;
		      	}
		    }
	  	}
	};
	return sdo;
};
