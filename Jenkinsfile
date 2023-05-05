pipeline {
    agent any
    stages {
        stage('Nettoyage') {
            steps {
               sh 'export TERM=xterm; make clean'
            }
        }  
        stage('build push_swap') {
            steps {
               sh 'export TERM=xterm; make push_swap'
            }
        }  
        stage('build checker') {
            steps {
                sh 'export TERM=xterm; make checker'
            }    
        }
        stage('Test') {
            steps {
                sh './push_swap 45 3 8 2 5 6 9 1 | ./checker 45 3 8 2 5 6 9 1'
            }
        }
    }   
}
