package Problem2;

public class Daily extends Appointment {


    public Daily(int appointmentYear, int appointmentMonth, int appointmentDay, String description) {
        super(appointmentYear, appointmentMonth, appointmentDay, description);
    }

    /*public Daily() {
    }*/

    @Override
    public boolean OccursOn(int year, int month, int day) {
        return true;
    }
}
