function income(id, name, money, account, date){
  this.id = (id == undefined || id === null) ? uniqid() : id;//string
  this.name = (name == undefined || name === null) ? "" : name;//string
  this.money = (money == undefined || money === null) ? 0.00 : Number(money);//string
  this.account = (account == undefined || account === null) ? null : account;//string
  this.date = (date == undefined || date === null) ? new Date() : new Date(date);//string
}

routeControllers.controller('spentCtrl', ['$scope','accounts','incomes',function($scope, accounts, incomes){
  	displayList();
  	function displayList(){
		$scope.accounts = accounts.getAccounts();
		$scope.incomes = [];
		var list = incomes.getIncomes();
  		for (var i=0;i<list.length;i++){
  			$scope.incomes.push(modelToDisplay(list[i]));
  		}
		$(document).ready(function() {
    		$('select').material_select();
  		});
		$(document).ready(function(){
        	$('.collapsible').collapsible();
      	});
	}

	function modelToDisplay(s){
  		var ss = new income(s.id, s.name, s.money, s.account, s.date);
  		ss.account = accounts.get(ss.account);
  		return ss;
  	}

  	$scope.hide = function(id){
		$(id).hide();
	}

	$scope.showAddForm = function(){
		$('#modalCreate').show();
		var s = modelToDisplay(new income());
		$scope.income = s;
	}

	$scope.showUpdateForm = function(income){
		$('#modalUpdate').show();
		$scope.income = income;
	}

  	$scope.create = function(obj){
      var income = new income(null, obj.name, obj.money, obj.account, obj.date);
    	incomes.add(income, function(){
        $scope.$apply(function(){
          $scope.incomes.push(modelToDisplay(income));
        });
    		$('#modalCreate').hide();
        Materialize.toast(income.name+" created", 2000);
    	}, function(){
    		console.log("Create income failed");
    	});
  	}

  	$scope.update = function(income){
    	incomes.update(income, function(){
    		$('#modalUpdate').hide();
        	Materialize.toast(income.name+" updated", 2000);
    	}, function(){
    		console.log("Update income failed");
    	});
  	}

  	$scope.delete = function(income){
    	incomes.delete(income, function(){
    		var len = $scope.incomes.length;
        $scope.$apply(function(){
          for (var i=0;i<len;i++){
            if (income.id == $scope.incomes[i].id){
              $scope.incomes.splice(i, 1);
            }
          }
        });
        Materialize.toast(income.name+" deleted", 2000);
    	}, function(){
    		console.log("delete income failed");
    	});
  	}

}]);
