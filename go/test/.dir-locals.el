((nil . ((eval . (set (make-local-variable 'project-dir)
					  (file-name-directory
					   (let ((d (dir-locals-find-file ".")))
						 (if (stringp d) d (car d))))))
		 (eval . (message "Project directory set to `%s'." project-dir))))

 (go-mode . ((eval . (let ((gopath (getenv "GOPATH")))
					   (if (not (string-match-p project-dir gopath))
						   (progn
							 (setenv "GOPATH" (concat (getenv "GOPATH") ":" project-dir))
							 (setenv "PATH" (concat (getenv "PATH") ":" (concat project-dir "bin")))))))
			 ))
 )
