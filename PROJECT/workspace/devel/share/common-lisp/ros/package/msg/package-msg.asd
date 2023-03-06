
(cl:in-package :asdf)

(defsystem "package-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "integer" :depends-on ("_package_integer"))
    (:file "_package_integer" :depends-on ("_package"))
    (:file "integer" :depends-on ("_package_integer"))
    (:file "_package_integer" :depends-on ("_package"))
  ))