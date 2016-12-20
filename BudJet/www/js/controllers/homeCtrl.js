routeControllers.controller('homeCtrl', ['$scope', 'accounts', 'spents', 'cathegories',
    function($scope, accounts, spents, cathegories){
      $('.button-collapse').sideNav({
          menuWidth: 300, // Default is 240
          edge: 'left', // Choose the horizontal origin
          closeOnClick: true // Closes side-nav on <a> clicks, useful for Angular/Meteor
      });
      
      cathegories.load(function(){
        console.log("cathegories loaded");
        accounts.load(function(){
          console.log("accounts loaded");
          spents.load(function(){
            console.log("spents loaded");
            displayDiagram();
          });
        });
      });

      function displayDiagram(){
        var ctx = document.getElementById("myChart");
        var res = [];
        var c = cathegories.getCathegories();
        var s = spents.getSpents();
        var data = {
          labels: [],
          datasets: null
        };

        for (var i=0;i<c.length;i++){
          res[c[i].name] =  0;
        }
        for (var i =0;i<s.length;i++){
          res[s[i].cathegory] = res[s[i].cathegory] + Number(s[i].cost);
        }
        var tmpdata = [];
        var tmpback = [];
        var tmphover = [];
        for (var i in res){
          if (res[i] > 0){
            tmpdata.push(res[i]);
            var c = cathegories.get(i);
            tmpback.push(c.colorCode);
            tmphover.push(c.colorCode);
            data.labels.push(i);
          }
        }
        data.datasets = [{
          data : tmpdata,
          backgroundColor: tmpback,
          hoverBackgroundColor: tmphover
        }];

        var  options = {
          animation: {animateRotate:true}
        };

        var myDoughnutChart = new Chart(ctx, {
            type: 'doughnut',
            data: data,
            options: options
        });
      }
    }
]);
