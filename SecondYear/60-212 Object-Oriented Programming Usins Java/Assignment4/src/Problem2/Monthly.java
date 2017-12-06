package Problem2;

public class Monthly extends Appointment {

    public Monthly(int appointmentYear, int appointmentMonth, int appointmentDay, String description) {
        super(appointmentYear, appointmentMonth, appointmentDay, description);
    }

    public Monthly() {
    }

    @Override
    public boolean OccursOn(int year, int month, int day) {

        if (super.appointmentDay == day){
            return true;
        } else {
            return false;
        }
    }
}

