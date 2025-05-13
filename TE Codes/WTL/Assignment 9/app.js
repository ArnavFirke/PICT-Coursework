var app = angular.module("registrationApp", []);

app.controller("registrationController", function ($scope) {
  $scope.register = function () {
    console.log(
      "Registration Data:",
      "\nFirst name: ",
      $scope.firstName,
      "\nLast name: ",
      $scope.lastName,
      "\nUsername: ",
      $scope.username,
      "\nPassword: " ,
      $scope.password
    );
    // Reset form fields after registration
    $scope.firstName = "";
    $scope.lastName = "";
    $scope.username = "";
    $scope.password = "";
  };
});

app.controller("loginController", function ($scope) {
  $scope.login = function () {
    console.log(
      "Login Data:",
      "\nUsername: ",
      $scope.username,
      "\nPassword: ",
      $scope.password
    );

    $scope.username = "";
    $scope.password = "";
  };
});
