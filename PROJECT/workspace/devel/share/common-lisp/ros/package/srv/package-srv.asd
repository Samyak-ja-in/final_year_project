
(cl:in-package :asdf)

(defsystem "package-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "addint" :depends-on ("_package_addint"))
    (:file "_package_addint" :depends-on ("_package"))
  ))